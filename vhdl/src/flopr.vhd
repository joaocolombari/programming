--
--

entity flopr is
	port(
		clk, reset: in BIT;
		d: in BIT_VECTOR(31 downto 0);
		q: out BIT_VECTOR(31 downto 0)
	);
end flopr;

architecture asynchronous of flopr is
begin

	-- Implementacao de um registrador
	-- ativo em borda positiva de clock
	-- e reset assíncrono em '1'
	
end;