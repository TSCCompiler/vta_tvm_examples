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

`ifndef LANES
`define LANES 4
`endif

module driver (
    input  wire          clock,
    input  wire          reset,
    input  wire [32-1:0] opcode,
    input  wire [32-1:0] id,
    input  wire [32-1:0] in,
    input  wire [32-1:0] addr,
    output reg [32-1:0] out
);

    reg [32*`LANES-1:0] wr_a;
    reg [32*`LANES-1:0] wr_b;
    wire [32*`LANES-1:0] ar_y;
//    always_comb begin
    always@(opcode or id or in or addr)  begin
        case(opcode)
            32'd0 : begin  out = 32'hdeadbeef;
            end
            32'd1 : begin
                case(id)
//                    32'd0 : driver.dut.cc[32*addr+:32] = in; //write_cc(in, addr);
                    32'd1 : wr_a[32*addr+:32] = in;//write_reg_a(in, addr);
                    32'd2 : wr_b[32*addr+:32] = in;//write_reg_b(in, addr);
//                    32'd3 : ar_y[32*addr+:32] = in;//write_reg_y(in, addr);
                endcase
            end
            32'd2 : begin
                case(id)
                    32'd0 : out = 0;//driver.dut[0].cc[32*addr+:32];//read_cc(addr);
//                    32'd1 : out = driver.dut.ra[32*addr+:32];//read_reg_a(addr);
//                    32'd2 : out = driver.dut.rb[32*addr+:32];//read_reg_b(addr);
                    32'd3 : out = ar_y[32*addr+:32];//read_reg_y(addr);
                endcase
            end
        endcase
    end

//    add #(.LANES(1)) dut4 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*4-1:0]), .rb(wr_b[32*4-1:0]), .ry(ar_y[32*4-1:0]));

//     add #(.LANES(1)) dut3 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*3-1:0]), .rb(wr_b[32*3-1:0]), .ry(ar_y[32*3-1:0]));

//     add #(.LANES(1)) dut2 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*2-1:32]), .rb(wr_b[32*2-1:32]), .ry(ar_y[32*2-1:32]));

//     add #(.LANES(1)) dut1 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*1-1:0]), .rb(wr_b[32*1-1:0]), .ry(ar_y[32*1-1:0]));

//    case(`LANES)
//    32'd4:  add #(.LANES(1)) dut4 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*4-1:0]), .rb(wr_b[32*4-1:0]), .ry(ar_y[32*4-1:0]));
//     32'd3: add #(.LANES(1)) dut3 (.clock(clock), .reset(reset),
//     .ra(wr_a[32*4-1:0]), .rb(wr_b[32*4-1:0]), .ry(ar_y[32*4-1:0]));
//    endcase

      genvar i;
      generate
        for(i = 1; i <= `LANES; i=i+1) begin
            add #(.LANES(1)) dut (.clock(clock), .reset(reset),
                    .ra(wr_a[32*i-1:32*(i-1)]), .rb(wr_b[32*i-1:32*(i-1)]), .ry(ar_y[32*i-1:32*(i-1)]));
        end
      endgenerate

endmodule
