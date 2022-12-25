// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See TOP.h for the primary calling header

#include "TOP.h"
#include "TOP__Syms.h"

//==========

TOP::TOP(const char* __VCname)
    : VerilatedModule(__VCname)
 {
    TOP__Syms* __restrict vlSymsp = __VlSymsp = new TOP__Syms(this, name());
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void TOP::__Vconfigure(TOP__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

TOP::~TOP() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void TOP::_settle__TOP__2(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_settle__TOP__2\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0U != vlTOPp->opcode)) {
        if ((1U == vlTOPp->opcode)) {
            if ((1U == vlTOPp->id)) {
                VL_ASSIGNSEL_WIII(32,(0x7fU & (vlTOPp->addr 
                                               << 5U)), vlTOPp->driver__DOT__wr_a, vlTOPp->in);
            }
        }
    }
    if ((0U != vlTOPp->opcode)) {
        if ((1U == vlTOPp->opcode)) {
            if ((1U != vlTOPp->id)) {
                if ((2U == vlTOPp->id)) {
                    VL_ASSIGNSEL_WIII(32,(0x7fU & (vlTOPp->addr 
                                                   << 5U)), vlTOPp->driver__DOT__wr_b, vlTOPp->in);
                }
            }
        }
    }
    vlTOPp->driver__DOT__ar_y[0U] = vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[1U] = vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[2U] = vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[3U] = vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry;
    if ((0U == vlTOPp->opcode)) {
        vlTOPp->out = 0xdeadbeefU;
    } else {
        if ((1U != vlTOPp->opcode)) {
            if ((2U == vlTOPp->opcode)) {
                if ((0U == vlTOPp->id)) {
                    vlTOPp->out = 0U;
                } else {
                    if ((3U == vlTOPp->id)) {
                        vlTOPp->out = (((0U == (0x1fU 
                                                & (vlTOPp->addr 
                                                   << 5U)))
                                         ? 0U : (vlTOPp->driver__DOT__ar_y[
                                                 ((IData)(1U) 
                                                  + 
                                                  (3U 
                                                   & vlTOPp->addr))] 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & (vlTOPp->addr 
                                                      << 5U))))) 
                                       | (vlTOPp->driver__DOT__ar_y[
                                          (3U & vlTOPp->addr)] 
                                          >> (0x1fU 
                                              & (vlTOPp->addr 
                                                 << 5U))));
                    }
                }
            }
        }
    }
}

void TOP::_eval_initial(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_eval_initial\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void TOP::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::final\n"); );
    // Variables
    TOP__Syms* __restrict vlSymsp = this->__VlSymsp;
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void TOP::_eval_settle(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_eval_settle\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void TOP::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    opcode = VL_RAND_RESET_I(32);
    id = VL_RAND_RESET_I(32);
    in = VL_RAND_RESET_I(32);
    addr = VL_RAND_RESET_I(32);
    out = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, driver__DOT__wr_a);
    VL_RAND_RESET_W(128, driver__DOT__wr_b);
    VL_RAND_RESET_W(128, driver__DOT__ar_y);
    driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc = VL_RAND_RESET_I(32);
    driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
