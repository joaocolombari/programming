--
--

entity regfile is
	port(
		clk: in BIT;
		we3: in BIT;
		a1, a2, a3: in BIT_VECTOR(4 downto 0);
		wd3: in BIT_VECTOR(31 downto 0);
		rd1, rd2: out BIT_VECTOR(31 downto 0)
	);
end regfile;

architecture behave of regfile is
	type ramtype is array (31 downto 0) of BIT_VECTOR(31 downto 0);
	signal mem: ramtype;
begin
	-- three ported register file
	-- read two ports combinationally (A1/RD1, A2/RD2)
	-- write third port on rising edge of clock (A3/WD3/WE3)
	-- register 0 hardwired to 0
	process(clk) begin
		if (clk'event and clk='1') then
			if we3 = '1' then mem(to_uinteger(a3)) <= wd3;
			end if;
		end if;
	end process;
	process(a1, a2, mem) begin
		if (to_uinteger(a1) = 0) then rd1 <= (others => '0');
		else rd1 <= mem(to_uinteger(a1));
		end if;
		if (to_uinteger(a2) = 0) then rd2 <= (others => '0');
		else rd2 <= mem(to_uinteger(a2));
		end if;
	end process;
end;