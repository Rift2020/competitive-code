module top_module ( 
    input [15:0] a, b,
    input cin,
    output cout,
    output [15:0] sum );
	wire co[15:0];
	bcd_fadd i1(.a(a[3:0]),.b(b[3:0]),.cin(cin),.cout(co[0]),.sum(sum[3:0]));

endmodule

