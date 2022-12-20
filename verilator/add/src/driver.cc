/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <iostream>

#include "Top.h"
#include "verilator_device.h"
#include <verilated.h>
#include <verilated_vcd_c.h>

struct VerilatedContextHandle{
    VerilatedVcdC* tfp = nullptr;
    Top         *  top = nullptr;
};

vluint64_t main_time = 0;
vluint64_t global_time = 0;
double sc_time_stamp() { return main_time; }

namespace tvm {
namespace runtime {
namespace contrib {

extern "C" VerilatorHandle VerilatorAlloc() {
    VerilatedContextHandle* context = new VerilatedContextHandle;
  Top* top = new Top;
  context->top = top;
//  VerilatedVcdFile* nfile = new VerilatedVcdFile();
  context->tfp = new VerilatedVcdC();
    Verilated::traceEverOn(true);
    top->trace(context->tfp, 0);
  context->tfp->open("./wave.vcd");

  std::cout << "set wave traced\n";
  return static_cast<VerilatorHandle>(context);
}

extern "C" void VerilatorDealloc(VerilatorHandle handle) {
    std::cout << "dealloc context\n";
    auto* context = static_cast<VerilatedContextHandle*>(handle);
    delete context->top;
    context->tfp->close();
    delete context->tfp;
    delete context;
}

extern "C" int VerilatorRead(VerilatorHandle handle, int id, int addr) {
    std::cout << "begin to read\n";
    auto* context = static_cast<VerilatedContextHandle*>(handle);

  Top* top = context->top;// static_cast<Top*>(handle);
  top->opcode = 2;
  top->id = id;
  top->addr = addr;
  top->eval();
  return top->out;
}

extern "C" void VerilatorWrite(VerilatorHandle handle, int id, int addr, int value) {
    std::cout << "begin to write\n";
    auto* context = static_cast<VerilatedContextHandle*>(handle);
  Top* top = context->top;
  top->opcode = 1;
  top->id = id;
  top->addr = addr;
  top->in = value;
  top->eval();
}

extern "C" void VerilatorReset(VerilatorHandle handle, int n) {
    auto* context = static_cast<VerilatedContextHandle*>(handle);
    std::cout << "enter verilator reset " << n;
  Top* top = context->top;
  top->opcode = 0;
  top->clock = 0;
  top->reset = 1;
  main_time = 0;
//  Verilated::timeunit()
  while (!Verilated::gotFinish() && main_time < static_cast<vluint64_t>(n * 10)) {
    if ((main_time % 10) == 1) {
      top->clock = 1;
    }
    if ((main_time % 10) == 6) {
      top->reset = 0;
    }
    top->eval();
    std::cout << "begin to dump to file "<<global_time<<"\n";
      context->tfp->dump(global_time);
      std::cout << "end dumping\n";
    main_time++;
    global_time++;
  }
  top->reset = 0;
}

extern "C" void VerilatorRun(VerilatorHandle handle, int n) {
    auto* context = static_cast<VerilatedContextHandle*>(handle);
  Top* top = context->top;
  top->opcode = 0;
  top->clock = 0;
  main_time = 0;
  while (!Verilated::gotFinish() && main_time < static_cast<vluint64_t>(n * 10)) {
    if ((main_time % 10) == 1) {
      top->clock = 1;
    }
    if ((main_time % 10) == 6) {
      top->clock = 0;
    }
    top->eval();
    context->tfp->dump(global_time);
    main_time++;
    global_time++;
  }
}

}  // namespace contrib
}  // namespace runtime
}  // namespace tvm
