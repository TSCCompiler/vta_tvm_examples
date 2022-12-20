`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/11 21:04:15
// Design Name: 
// Module Name: add_testbench2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module add_testbench2(

    );
    
    
    
    
    reg sys_clk;
    reg sys_reset;
    reg [32-1:0] opcode;
    reg [32-1:0] id;
    reg [32-1:0] in;
    reg [32-1:0] addr;
   wire [32-1:0] out;
    
    driver u_driver(.clock(sys_clk),
        .reset(sys_reset),
        .opcode(opcode),
        .id(id),
        .in(in),
        .addr(addr),
        .out(out)
    );
    
    initial begin
        sys_clk = 1'b1;
        sys_reset = 1'b1;
        #40
        sys_reset = 1'b0;
        opcode=1;id=1;addr=0;in=5;
        #20
        opcode=1;id=2;addr=0;in=6;
        #20
        opcode=2;id=3;addr=0;
    end
    
    always begin 
        #10
        sys_clk = ~sys_clk;
        
    end
endmodule
