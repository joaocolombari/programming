--
--

entity controller is
	port(
		op: in BIT_VECTOR(6 downto 0);
		funct3: in BIT_VECTOR(2 downto 0);
		funct7b5, Zero: in BIT;
		ResultSrc: out BIT_VECTOR(1 downto 0);
		MemWrite: out BIT;
		PCSrc, ALUSrc: out BIT;
		RegWrite: out BIT;
		Jump: buffer BIT;
		ImmSrc: out BIT_VECTOR(1 downto 0);
		ALUControl: out BIT_VECTOR(2 downto 0)
	);
end controller;

architecture struct of controller is
	
	signal ALUOp: BIT_VECTOR(1 downto 0);
	signal Branch: BIT;
begin
	md: maindec port map(op, ResultSrc, MemWrite, Branch,
							ALUSrc, RegWrite, Jump, ImmSrc, ALUOp);
	ad: aludec port map(op(5), funct3, funct7b5, ALUOp, ALUControl);
	PCSrc <= (Branch and Zero) or Jump;
end;