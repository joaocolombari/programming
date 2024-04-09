--
--

entity extend is
	port(
		instr: in BIT_VECTOR(31 downto 7);
		immsrc: in BIT_VECTOR(1 downto 0);
		immext: out BIT_VECTOR(31 downto 0)
	);
end extend;

architecture behave of extend is
begin
	process(instr, immsrc) begin
		case immsrc is
			-- I-type
			when "00" =>
				immext <= (Width-1 downto 12 => instr(31)) & instr(31 downto 20);
			-- S-types (stores)
			when "01" =>
				immext <= (Width-1 downto 12 => instr(31)) & instr(31 downto 25) & instr(11 downto 7);
			-- B-type (branches)
			when "10" =>
				immext <= (Width-1 downto 12 => instr(31)) & instr(7) & instr(30 downto 25) & instr(11 downto 8) & '0';
			-- J-type (jal)
			when "11" =>
				immext <= (Width-1 downto 20 => instr(31)) & instr(19 downto 12) & instr(20) & instr(30 downto 21) & '0';
			when others =>
				immext <= (Width-1 downto 0 => '0');
		end case;
	end process;
end;