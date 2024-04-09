-- 
-- Atividade 7 - A sétima atividade é incluir no pacote riscv_pkg (arquivo riscv_pkg), na pasta src, as seguintes funções:
-- 
-- i - uma função chamada to_uinteger, que converte um objeto do tipo bit_vector para integer sem sinal.
--
-- ii - criar uma função sobrecarregando o operador “+”, que realize a soma de dois objetos do tipo bit_vector.
--
-- iii - criar uma função sobrecarregando o operador “-”, que realize a subtração de dois objetos do tipo bit_vector, 
-- fazendo uso do operador sobrecarregado “+”.
--
--	Joao Victor Colombari Carlet - nro USP 5274502
--	
--	8 de Novembro de 2023 
--

library work; 
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.all;

package riscv_pkg is

    constant RISCV_Data_Width : natural := 32;
    

    -- Definicao de componentes 
    -- Componente Mux2
    component mux2 is
        port(
		d0, d1: in 		BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		s: 		in 		BIT;
		y: 		out 	BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component mux2;

    -- Componente Mux3 
    component mux3 is
        port(
		d0, d1, d2:     in      BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		s:              in      BIT_VECTOR(1 downto 0);
		y:              out     BIT_VECTOR(RISCV_Data_Width- 1 downto 0)
	    );
    end component mux3;

    -- Componente flopr
    component flopr is
        port(
		clk, reset:     in      BIT;
		d:              in      BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		q:              out     BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component flopr;

    -- Componente flopenr
    component flopenr is
        port(
		clk, reset, en:     in      BIT;
		d:                  in      BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		q:                  out     BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component flopenr;

    -- Componente extend
    component extend is
        port(
		instr:      in      BIT_VECTOR(31 downto 7);
		immsrc:     in      BIT_VECTOR(1 downto 0);
		immext:     out     BIT_VECTOR(31 downto 0)
	    );
    end component extend;

end package riscv_pkg;