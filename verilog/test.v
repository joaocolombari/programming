module mux (
    input   a, b, 
    input   sel,
    output  reg y
);

always @(*) begin
    y <= (sel) ? a : b;
end
    
endmodule