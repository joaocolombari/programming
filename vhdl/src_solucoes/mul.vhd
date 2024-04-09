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

entity mul is 
    generic(
        Width : natural := 32
    );

    port(
        a, b:           in          BIT_VECTOR(Width - 1 downto 0);
        p               out         BIT_VECTOR(2 * Width - 1 downto 0)
    );
end mul;

architecture multiplication of mul is   
    signal a, b:                    BIT_VECTOR(Width - 1 downto 0);
    signal p0, p1:                  BIT_VECTOR(Width - 1 downto 0);
begin
    adder: full_adder
        port map(
            a => a,
            b => b,
            cin => 
        )
end multiplication;


architecture struct of datapath is	
	signal PCNext, PCPlus4, PCTarget: 
									BIT_VECTOR(Width - 1 downto 0);
	signal ImmExt: 					BIT_VECTOR(Width - 1 downto 0);
	signal SrcA, SrcB: 				BIT_VECTOR(Width - 1 downto 0);
	signal Result: 					BIT_VECTOR(Width - 1 downto 0);
begin
	-- next PC logic
	pcreg: flopr 
		-- generic map(32) 
		port map(
			clk => clk, 
			reset => reset, 
			d => PCNext, 
			q => PC
		);
end;

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