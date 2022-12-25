// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "TOP__Syms.h"


//======================

void TOP::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void TOP::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    TOP::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void TOP::traceInitTop(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void TOP::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+29,"clock", false,-1);
        tracep->declBit(c+30,"reset", false,-1);
        tracep->declBus(c+31,"opcode", false,-1, 31,0);
        tracep->declBus(c+32,"id", false,-1, 31,0);
        tracep->declBus(c+33,"in", false,-1, 31,0);
        tracep->declBus(c+34,"addr", false,-1, 31,0);
        tracep->declBus(c+35,"out", false,-1, 31,0);
        tracep->declBit(c+29,"driver clock", false,-1);
        tracep->declBit(c+30,"driver reset", false,-1);
        tracep->declBus(c+31,"driver opcode", false,-1, 31,0);
        tracep->declBus(c+32,"driver id", false,-1, 31,0);
        tracep->declBus(c+33,"driver in", false,-1, 31,0);
        tracep->declBus(c+34,"driver addr", false,-1, 31,0);
        tracep->declBus(c+35,"driver out", false,-1, 31,0);
        tracep->declArray(c+13,"driver wr_a", false,-1, 127,0);
        tracep->declArray(c+17,"driver wr_b", false,-1, 127,0);
        tracep->declArray(c+1,"driver ar_y", false,-1, 127,0);
        tracep->declBus(c+36,"driver genblk1[1] dut LANES", false,-1, 31,0);
        tracep->declBit(c+29,"driver genblk1[1] dut clock", false,-1);
        tracep->declBit(c+30,"driver genblk1[1] dut reset", false,-1);
        tracep->declBus(c+21,"driver genblk1[1] dut ra", false,-1, 31,0);
        tracep->declBus(c+22,"driver genblk1[1] dut rb", false,-1, 31,0);
        tracep->declBus(c+5,"driver genblk1[1] dut ry", false,-1, 31,0);
        tracep->declBus(c+6,"driver genblk1[1] dut cc", false,-1, 31,0);
        tracep->declBus(c+5,"driver genblk1[1] dut sry", false,-1, 31,0);
        tracep->declBus(c+36,"driver genblk1[2] dut LANES", false,-1, 31,0);
        tracep->declBit(c+29,"driver genblk1[2] dut clock", false,-1);
        tracep->declBit(c+30,"driver genblk1[2] dut reset", false,-1);
        tracep->declBus(c+23,"driver genblk1[2] dut ra", false,-1, 31,0);
        tracep->declBus(c+24,"driver genblk1[2] dut rb", false,-1, 31,0);
        tracep->declBus(c+7,"driver genblk1[2] dut ry", false,-1, 31,0);
        tracep->declBus(c+8,"driver genblk1[2] dut cc", false,-1, 31,0);
        tracep->declBus(c+7,"driver genblk1[2] dut sry", false,-1, 31,0);
        tracep->declBus(c+36,"driver genblk1[3] dut LANES", false,-1, 31,0);
        tracep->declBit(c+29,"driver genblk1[3] dut clock", false,-1);
        tracep->declBit(c+30,"driver genblk1[3] dut reset", false,-1);
        tracep->declBus(c+25,"driver genblk1[3] dut ra", false,-1, 31,0);
        tracep->declBus(c+26,"driver genblk1[3] dut rb", false,-1, 31,0);
        tracep->declBus(c+9,"driver genblk1[3] dut ry", false,-1, 31,0);
        tracep->declBus(c+10,"driver genblk1[3] dut cc", false,-1, 31,0);
        tracep->declBus(c+9,"driver genblk1[3] dut sry", false,-1, 31,0);
        tracep->declBus(c+36,"driver genblk1[4] dut LANES", false,-1, 31,0);
        tracep->declBit(c+29,"driver genblk1[4] dut clock", false,-1);
        tracep->declBit(c+30,"driver genblk1[4] dut reset", false,-1);
        tracep->declBus(c+27,"driver genblk1[4] dut ra", false,-1, 31,0);
        tracep->declBus(c+28,"driver genblk1[4] dut rb", false,-1, 31,0);
        tracep->declBus(c+11,"driver genblk1[4] dut ry", false,-1, 31,0);
        tracep->declBus(c+12,"driver genblk1[4] dut cc", false,-1, 31,0);
        tracep->declBus(c+11,"driver genblk1[4] dut sry", false,-1, 31,0);
    }
}

void TOP::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void TOP::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void TOP::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    TOP__Syms* __restrict vlSymsp = static_cast<TOP__Syms*>(userp);
    TOP* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->driver__DOT__ar_y),128);
        tracep->fullIData(oldp+5,(vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__sry),32);
        tracep->fullIData(oldp+6,(vlTOPp->driver__DOT__genblk1__BRA__1__KET____DOT__dut__DOT__cc),32);
        tracep->fullIData(oldp+7,(vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__sry),32);
        tracep->fullIData(oldp+8,(vlTOPp->driver__DOT__genblk1__BRA__2__KET____DOT__dut__DOT__cc),32);
        tracep->fullIData(oldp+9,(vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__sry),32);
        tracep->fullIData(oldp+10,(vlTOPp->driver__DOT__genblk1__BRA__3__KET____DOT__dut__DOT__cc),32);
        tracep->fullIData(oldp+11,(vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__sry),32);
        tracep->fullIData(oldp+12,(vlTOPp->driver__DOT__genblk1__BRA__4__KET____DOT__dut__DOT__cc),32);
        tracep->fullWData(oldp+13,(vlTOPp->driver__DOT__wr_a),128);
        tracep->fullWData(oldp+17,(vlTOPp->driver__DOT__wr_b),128);
        tracep->fullIData(oldp+21,(vlTOPp->driver__DOT__wr_a[0U]),32);
        tracep->fullIData(oldp+22,(vlTOPp->driver__DOT__wr_b[0U]),32);
        tracep->fullIData(oldp+23,(vlTOPp->driver__DOT__wr_a[1U]),32);
        tracep->fullIData(oldp+24,(vlTOPp->driver__DOT__wr_b[1U]),32);
        tracep->fullIData(oldp+25,(vlTOPp->driver__DOT__wr_a[2U]),32);
        tracep->fullIData(oldp+26,(vlTOPp->driver__DOT__wr_b[2U]),32);
        tracep->fullIData(oldp+27,(vlTOPp->driver__DOT__wr_a[3U]),32);
        tracep->fullIData(oldp+28,(vlTOPp->driver__DOT__wr_b[3U]),32);
        tracep->fullBit(oldp+29,(vlTOPp->clock));
        tracep->fullBit(oldp+30,(vlTOPp->reset));
        tracep->fullIData(oldp+31,(vlTOPp->opcode),32);
        tracep->fullIData(oldp+32,(vlTOPp->id),32);
        tracep->fullIData(oldp+33,(vlTOPp->in),32);
        tracep->fullIData(oldp+34,(vlTOPp->addr),32);
        tracep->fullIData(oldp+35,(vlTOPp->out),32);
        tracep->fullIData(oldp+36,(1U),32);
    }
}
