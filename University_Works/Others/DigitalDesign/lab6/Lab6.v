module Lab6(a,b,sel,out);
input a,b;
input [2:0]sel;
output out;

wire [0:6]i;
wire [2:0]seln;
wire [0:7]ans;
//MUX for 7 functions
mynot		x00( .a(a), .out(i[0]));//000
mynor		x01( .a(a), .b(b), .out(i[1]));//001
myand		x02( .a(a), .b(b), .out(i[2]));//010
myor		x03( .a(a), .b(b), .out(i[3]));//011
myxor		x04( .a(a), .b(b), .out(i[4]));//100
myxnor	    x05( .a(a), .b(b), .out(i[5]));//101
mynand	    x06( .a(a), .b(b), .out(i[6]));//110

invertsel   x10( .in(sel), .out(seln));

AND4X1      x20( .a(i[0]), .sel0(seln[0]), .sel1(seln[1]), .sel2(seln[2]), .out(ans[0]) );
AND4X1      x21( .a(i[1]), .sel0(sel[0]), .sel1(seln[1]), .sel2(seln[2]), .out(ans[1]) );
AND4X1      x22( .a(i[2]), .sel0(seln[0]), .sel1(sel[1]), .sel2(seln[2]), .out(ans[2]) );
AND4X1      x23( .a(i[3]), .sel0(sel[0]), .sel1(sel[1]), .sel2(seln[2]), .out(ans[3]) );
AND4X1      x24( .a(i[4]), .sel0(seln[0]), .sel1(seln[1]), .sel2(sel[2]), .out(ans[4]) );
AND4X1      x25( .a(i[5]), .sel0(sel[0]), .sel1(seln[1]), .sel2(sel[2]), .out(ans[5]) );
AND4X1      x26( .a(i[6]), .sel0(seln[0]), .sel1(sel[1]), .sel2(sel[2]), .out(ans[6]) );
AND4X1      x27( .a(i[6]), .sel0(sel[0]), .sel1(sel[1]), .sel2(sel[2]), .out(ans[7]) );

OR8X1       x30( .a(ans[0]), .b(ans[1]), .c(ans[2]), .d(ans[3]), .e(ans[4]), .f(ans[5]), .g(ans[6]), .h(ans[7]), .out(out));

endmodule

module OR8X1 ( a,b,c,d,e,f,g,h, out);
input a,b,c,d,e,f,g,h;
output out;
wire ab,cd,ef,gh,ad,eh;

myor        x00(a,b,ab);
myor        x01(c,d,cd);
myor        x02(e,f,ef);
myor        x03(g,h,gh);
myor        x04(ab,cd,ad);
myor        x05(ef,gh,eh);
myor        x06(ad,eh,out);

endmodule

module AND4X1 (a, sel0, sel1, sel2, out);
input a, sel0, sel1, sel2;
output out;

wire c1, c2;

myand       x01(a, sel0,c1);
myand       x02(c1,sel1,c2);
myand       x03(c2,sel2,out);

endmodule

module invertsel( in, out);
input   [2:0]in;
output  [2:0]out;

mynot   x0(.a(in[0]), .out(out[0]));
mynot   x1(.a(in[1]), .out(out[1]));
mynot   x2(.a(in[2]), .out(out[2]));

endmodule

//=================== 7 function modules =======================
module mynot (a,out);
input a;
output out;

//use nor gate to implement not gate
nor nor_00(out, a, a);

endmodule

module mynor(a, b, out);
input a, b;
output out;

nor nor_00(out, a, b);
endmodule



module myor(a,b,out);
input a,b;
output out;
wire c;
//use nor gate to implement or gate
nor nor_00(c,a,b);
nor nor_01(out,c,c);

endmodule



module myand(a,b,out);
input a,b;
output out;
wire ca, cb;
//use nor gate to implement and gate
nor nor_00(ca,a,a);
nor nor_01(cb,b,b);
nor nor_02(out,ca,cb);

endmodule



module mynand(a,b,out);
input a,b;
output out;
wire ca, cb, cand;
//use nor gate to implement NAND gate
nor nor_00(ca,a,a);
nor nor_01(cb,b,b);
nor nor_02(cand,ca,cb);
nor nor_03(out, cand,cand);

endmodule



module myxor(a,b,out);
input a,b;
output out;
wire axbn, anb, abn, cxnor;
//use nor gate to implement xor gate
nor nor_00(axbn,a,b);//a'b'
nor nor_01(anb,axbn,b);//(a'+b)' = ab'
nor nor_02(abn,a,axbn);//(a+b')' = a'b
nor nor_03(cxnor, abn,anb);// a'b' + ab
nor nor_04(out,cxnor,cxnor);

endmodule



module myxnor(a,b,out);
input a,b;
output out;
wire axbn, anb, abn;
//use nor to implement xnor gate
nor nor_00(axbn,a,b);//a'b'
nor nor_01(anb,axbn,b);//(a'+b)' = ab'
nor nor_02(abn,a,axbn);//(a+b')' = a'b
nor nor_03(out, abn,anb);// a'b' + ab

endmodule

