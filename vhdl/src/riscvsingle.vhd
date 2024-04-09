--
--

entity riscvsingle is
	port(
		clk, reset: in BIT;
		PC: out BIT_VECTOR(31 downto 0);
		Instr: in BIT_VECTOR(31 downto 0);
		MemWrite: out BIT;
		ALUResult, WriteData: out BIT_VECTOR(31 downto 0);
		ReadData: in BIT_VECTOR(31 downto 0)
	);
end riscvsingle;

architecture struct of riscvsingle is	
	signal ALUSrc, RegWrite, Jump, Zero, PCSrc: BIT;
	signal ResultSrc, ImmSrc: BIT_VECTOR(1 downto 0);
	signal ALUControl: BIT_VECTOR(2 downto 0);
begin
	c: controller port map(Instr(6 downto 0), Instr(14 downto 12),
							Instr(30), Zero, ResultSrc, MemWrite,
							PCSrc, ALUSrc, RegWrite, Jump,
							ImmSrc, ALUControl);
	dp: datapath generic map (32)
					 port map(clk, reset, ResultSrc, PCSrc, ALUSrc,
							RegWrite, ImmSrc, ALUControl, Zero,
							PC, Instr, ALUResult, WriteData,
							ReadData);
end;