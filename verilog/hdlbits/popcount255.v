module top_module( 
    input [254:0] in,
    output [7:0] out );
always @(*) begin
	out=0;
	for(int i=0;i<$bits(in);++i)
		out+=in[i];
end
endmodule
