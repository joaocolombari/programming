--
--

use work.riscv_pkg.all;

entity dmem is
	generic(
		Width : integer := 32
	);
	port(
		clk, we: in BIT;
		a, wd: in BIT_VECTOR(Width-1 downto 0);
		rd: out BIT_VECTOR(Width-1 downto 0)
	);
end dmem;

architecture behave of dmem is
begin
	process (clk, a) is
		type ramtype is array (63 downto 0) of BIT_VECTOR(Width-1 downto 0);
		variable mem: ramtype;
	begin
		-- read or write memory
		-- loop
		if (clk'event and clk='1') then
			if (we = '1') then mem(to_uinteger(a(7 downto 2))) := wd;
			end if;
		end if;
		rd <= mem(to_uinteger(a(7 downto 2)));
		--wait on clk, a;
		--end loop;
	end process;
end;