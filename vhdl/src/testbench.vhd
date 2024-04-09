--
--

entity testbench is
end;

architecture test of testbench is
	component top
		port(clk, reset: in BIT;
			WriteData, DataAdr: out BIT_VECTOR(31 downto 0);
			MemWrite: out BIT);
	end component;
	
	signal WriteData, DataAdr: BIT_VECTOR(31 downto 0);
	signal clk, reset, MemWrite: BIT;
begin
	-- instantiate device to be tested
	dut: top port map(clk, reset, WriteData, DataAdr, MemWrite);
	
	-- Generate clock with 10 ns period
	process begin
		clk <= '1';
		wait for 5 ns;
		clk <= '0';
		wait for 5 ns;
	end process;
	
	-- Generate reset for first two clock cycles
	process begin
		reset <= '1';
		wait for 22 ns;
		reset <= '0';
		wait;
	end process;
	
	-- check that 25 gets written to address 100 at end of program
	process(clk) begin
		if(clk'event and clk = '0' and MemWrite = '1') then
			if( to_uinteger(DataAdr) = 100 and
				to_uinteger(writedata) = 25) then
				report "NO ERRORS: Simulation succeeded" severity
				failure;
			elsif (to_uinteger(DataAdr) /= 96) then
				report "Simulation failed" severity failure;
			end if;
		end if;
	end process;
end;