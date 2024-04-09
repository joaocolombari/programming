--
/* 
	Atividade 1 - implementar um multiplexador de 2 para 1, 
	utilizando a construção with-select, e parametrizando o 
	barramento de dados com um parâmetro genérico de nome Width.

	Joao Victor Colombari Carlet - nro USP 5274502

	6 de Novembro de 2023
*/ 
--

entity mux2 is
	port(
		d0, d1: in BIT_VECTOR(31 downto 0);
		s: in BIT;
		y: out BIT_VECTOR(31 downto 0)
	);
end mux2;

architecture behave of mux2 is
begin
	with s select
        y <= d0 when '0',
        d1 when others;
end;