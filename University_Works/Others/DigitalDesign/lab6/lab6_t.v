`timescale 1ns/1ps

module lab6_t;
reg A;
reg B;
reg [2:0]Sel;
wire Out;

Lab6 DUT (A,B,Sel,Out);

initial begin
A <= 0;
B <= 0;
Sel <= 0;
$dumpfile("Lab6.vcd");
$dumpvars;
 end

always #20 Sel <= Sel + 1;

always@(Sel)
begin
	A <= 0;
	B <= 0;
	#5; 
	A <= 0;
	B <= 1;
	#5; 
	A <= 1;
	B <= 0;
	#5; 
	A <= 1;
	B <= 1;
end

always #5 $display ("Sel: %d A = %d, B = %d, out = %d", Sel, A, B, Out);

initial #160 $finish;

endmodule
