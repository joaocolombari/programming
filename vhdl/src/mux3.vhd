--
--

entity mux3 is
	port(
		d0, d1, d2: in BIT_VECTOR(31 downto 0);
		s: in BIT_VECTOR(1 downto 0);
		y: out BIT_VECTOR(31 downto 0)
	);
end mux3;

architecture behave of mux3 is
begin

	-- Descricao do multiplexador 3x1 utilizando WHEN-ELSE

end;