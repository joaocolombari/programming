--
--

entity alu is
	port(
		a, b: in BIT_VECTOR(31 downto 0);
		ALUControl: in BIT_VECTOR(2 downto 0);
		ALUResult: out BIT_VECTOR(31 downto 0);
		--Overflow: out BIT;
		Zero: out BIT
	);
end alu;

architecture synth of alu is
	constant Result_Zero: BIT_VECTOR(31 downto 0) := (others => '0');
	signal S, Bout, Carry: BIT_VECTOR(31 downto 0);
begin
	Carry <= "0000000000000000000000000000000" & ALUControl(2);
	Bout <= (not b) when (ALUControl(2) = '1') else b;
	S <= a + Bout + Carry;

	-- alu function
	process(a, b, ALUControl, S)
		variable ALUResultTmp: BIT_VECTOR(31 downto 0) := "00000000000000000000000000000000";
	begin
		case ALUControl(2 downto 0) is
			when "000" => ALUResultTmp := a + b;
			when "001" => ALUResultTmp := a - b;
			when "010" => ALUResultTmp := a and b;
			when "011" => ALUResultTmp := a or b;
			when "101" => ALUResultTmp := "0000000000000000000000000000000" & S(31);
			when others => ALUResultTmp := Result_Zero;
		end case;
		ALUResult <= ALUResultTmp;
		Zero <= '1' when (ALUResultTmp = Result_Zero) else '0';
	end process;
	-- overflow circuit
	--process(all) begin
	--	case ALUControl(2 downto 1) is
	--		when "01" => Overflow <=
	--					(a(31) and b(31) and (not (S(31)))) or
	--					((not a(31)) and (not b(31)) and S(31));
	--		when "11" => Overflow <=
	--					((not a(31)) and b(31) and S(31)) or
	--					(a(31) and (not b(31)) and (not S(31)));
	--		when others => Overflow <= '0';
	--	end case;
	--end process;
end;