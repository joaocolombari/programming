--
--

entity adder is
	port(
		a, b: in BIT_VECTOR(31 downto 0);
		y: out BIT_VECTOR(31 downto 0)
	);
end adder;

architecture behave of adder is
begin
	y <= a + b;
end;