--
-- Implementar a instrução MUL, fazendo uso da resolução expandida do exercício 7.6.6.
-- Apresentar código com comentários e simulação da instrução.
--
--	Joao Victor Colombari Carlet - nro USP 5274502
--	
--	30 de Novembro de 2023 
--

library work;
use work.riscv_pkg.all;
 
entity full_adder is
    generic(
        Width : natural := 32
    );

    port( 
        a,b :           in          BIT_VECTOR(Width - 1 downto 0);
        cin :           in          BIT_VECTOR(Width - 1 downto 0);
        y :             out         BIT_VECTOR(Width - 1 downto 0);
        cout :          out         BIT_VECTOR(Width - 1 downto 0)
    );
end full_adder;
 
architecture behave of full_adder is
begin
    y <= a XOR b XOR cin;
    cout <= (a AND b) OR (cin AND a) OR (cin AND b);
end;