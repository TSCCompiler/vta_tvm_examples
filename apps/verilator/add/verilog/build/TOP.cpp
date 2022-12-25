// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See TOP.h for the primary calling header

#include "TOP.h"
#include "TOP__Syms.h"

//==========

void TOP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate TOP::eval\n"); );
    TOP__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("driver.v", 24, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void TOP::_eval_initial_loop(TOP__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("driver.v", 24, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void TOP::_sequent__TOP__1(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_sequent__TOP__1\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry = 0U;
        vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry = 0U;
    } else {
        vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc 
            = ((IData)(1U) + vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc);
        vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc 
            = ((IData)(1U) + vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc);
        vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc 
            = ((IData)(1U) + vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc);
        vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc 
            = ((IData)(1U) + vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc);
        vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry 
            = (vlTOPp->driver__DOT__wr_a[3U] + vlTOPp->driver__DOT__wr_b[3U]);
        vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry 
            = (vlTOPp->driver__DOT__wr_a[2U] + vlTOPp->driver__DOT__wr_b[2U]);
        vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry 
            = (vlTOPp->driver__DOT__wr_a[1U] + vlTOPp->driver__DOT__wr_b[1U]);
        vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry 
            = (vlTOPp->driver__DOT__wr_a[0U] + vlTOPp->driver__DOT__wr_b[0U]);
    }
    vlTOPp->driver__DOT__ar_y[3U] = vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[2U] = vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[1U] = vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry;
    vlTOPp->driver__DOT__ar_y[0U] = vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry;
}

VL_INLINE_OPT void TOP::_combo__TOP__3(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_combo__TOP__3\n"); );
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

void TOP::_eval(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_eval\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData TOP::_change_request(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_change_request\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData TOP::_change_request_1(TOP__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_change_request_1\n"); );
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void TOP::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    TOP::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
