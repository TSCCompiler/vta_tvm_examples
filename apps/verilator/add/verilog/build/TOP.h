// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _TOP_H_
#define _TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class TOP__Syms;
class TOP_VerilatedVcd;


//----------

VL_MODULE(TOP) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN(opcode,31,0);
    VL_IN(id,31,0);
    VL_IN(in,31,0);
    VL_IN(addr,31,0);
    VL_OUT(out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    WData/*127:0*/ driver__DOT__wr_a[4];
    WData/*127:0*/ driver__DOT__wr_b[4];
    WData/*127:0*/ driver__DOT__ar_y[4];
    IData/*31:0*/ driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc;
    IData/*31:0*/ driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry;
    IData/*31:0*/ driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc;
    IData/*31:0*/ driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry;
    IData/*31:0*/ driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc;
    IData/*31:0*/ driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry;
    IData/*31:0*/ driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc;
    IData/*31:0*/ driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    TOP__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(TOP);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    TOP(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~TOP();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(TOP__Syms* __restrict vlSymsp);
    void __Vconfigure(TOP__Syms* symsp, bool first);
  private:
    static QData _change_request(TOP__Syms* __restrict vlSymsp);
    static QData _change_request_1(TOP__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(TOP__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(TOP__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(TOP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(TOP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(TOP__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(TOP__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
