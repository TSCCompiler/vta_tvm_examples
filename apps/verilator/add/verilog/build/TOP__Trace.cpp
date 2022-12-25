// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "TOP__Syms.h"


void TOP::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void TOP::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgWData(oldp+0,(vlTOPp->driver__DOT__ar_y),128);
            tracep->chgIData(oldp+4,(vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry),32);
            tracep->chgIData(oldp+5,(vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc),32);
            tracep->chgIData(oldp+6,(vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry),32);
            tracep->chgIData(oldp+7,(vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc),32);
            tracep->chgIData(oldp+8,(vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry),32);
            tracep->chgIData(oldp+9,(vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc),32);
            tracep->chgIData(oldp+10,(vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry),32);
            tracep->chgIData(oldp+11,(vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgWData(oldp+12,(vlTOPp->driver__DOT__wr_a),128);
            tracep->chgWData(oldp+16,(vlTOPp->driver__DOT__wr_b),128);
            tracep->chgIData(oldp+20,(vlTOPp->driver__DOT__wr_a[0U]),32);
            tracep->chgIData(oldp+21,(vlTOPp->driver__DOT__wr_b[0U]),32);
            tracep->chgIData(oldp+22,(vlTOPp->driver__DOT__wr_a[1U]),32);
            tracep->chgIData(oldp+23,(vlTOPp->driver__DOT__wr_b[1U]),32);
            tracep->chgIData(oldp+24,(vlTOPp->driver__DOT__wr_a[2U]),32);
            tracep->chgIData(oldp+25,(vlTOPp->driver__DOT__wr_b[2U]),32);
            tracep->chgIData(oldp+26,(vlTOPp->driver__DOT__wr_a[3U]),32);
            tracep->chgIData(oldp+27,(vlTOPp->driver__DOT__wr_b[3U]),32);
        }
        tracep->chgBit(oldp+28,(vlTOPp->clock));
        tracep->chgBit(oldp+29,(vlTOPp->reset));
        tracep->chgIData(oldp+30,(vlTOPp->opcode),32);
        tracep->chgIData(oldp+31,(vlTOPp->id),32);
        tracep->chgIData(oldp+32,(vlTOPp->in),32);
        tracep->chgIData(oldp+33,(vlTOPp->addr),32);
        tracep->chgIData(oldp+34,(vlTOPp->out),32);
    }
}

void TOP::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
