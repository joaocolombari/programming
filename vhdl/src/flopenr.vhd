--
--

entity flopenr is
	port(
		clk, reset, en: in BIT;
		d: in BIT_VECTOR(31 downto 0);
		q: out BIT_VECTOR(31 downto 0)
	);
end flopenr;

architecture asynchronous of flopenr is
begin

	-- Implementacao de um registrador
	-- ativo em borda positiva de clock,
	-- com clock enable
	-- e reset assíncrono em '1'

end;