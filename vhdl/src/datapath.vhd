--
--

use work.riscv_pkg.all;

entity datapath is
	port(
		clk, reset: in BIT;
		ResultSrc: in BIT_VECTOR(1 downto 0);
		PCSrc, ALUSrc: in BIT;
		RegWrite: in BIT;
		ImmSrc: in BIT_VECTOR(1 downto 0);
		ALUControl: in BIT_VECTOR(2 downto 0);
		Zero: out BIT;
		PC: buffer BIT_VECTOR(31 downto 0);
		Instr: in BIT_VECTOR(31 downto 0);
		ALUResult, WriteData: buffer BIT_VECTOR(31 downto 0);
		ReadData: in BIT_VECTOR(31 downto 0)
	);
end datapath;

architecture struct of datapath is	
	signal PCNext, PCPlus4, PCTarget: BIT_VECTOR(31 downto 0);
	signal ImmExt: BIT_VECTOR(31 downto 0);
	signal SrcA, SrcB: BIT_VECTOR(31 downto 0);
	signal Result: BIT_VECTOR(31 downto 0);
begin
	-- next PC logic
	pcreg: flopr generic map(32) port map(clk, reset, PCNext, PC);
	pcadd4: adder generic map(32) port map(PC, X"00000004", PCPlus4);
	pcaddbranch: adder generic map(32) port map(PC, ImmExt, PCTarget);
	pcmux: mux2 generic map(32) port map(PCPlus4, PCTarget, PCSrc,
											PCNext);
	-- register file logic
	rf: regfile generic map(32) port map(clk, RegWrite, Instr(19 downto 15),
	Instr(24 downto 20), Instr(11 downto 7),
								Result, SrcA, WriteData);
	ext: extend generic map(32) port map(Instr(31 downto 7), ImmSrc, ImmExt);
	-- ALU logic
	srcbmux: mux2 generic map(32) port map(WriteData, ImmExt,
											ALUSrc, SrcB);
	mainalu: alu generic map(32) port map(SrcA, SrcB, ALUControl, ALUResult, Zero);
	resultmux: mux3 generic map(32) port map(ALUResult, ReadData,
												PCPlus4, ResultSrc,
												Result);
end;