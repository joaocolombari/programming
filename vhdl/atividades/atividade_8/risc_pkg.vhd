-- A oitava atividade é incluir o arquivo alu.vhd, que deverá ser definido como toplevel. Realize alterações na entidade alu de forma a:
--
-- i) simplificar a linha 28;
--
-- ii) parametrizar o barramento de dados com um parâmetro genérico de nome Width;
--
-- iii) incluir sua declaração de componente no pacote riscv_pkg;
--
-- iv) indicar se é possível propor uma melhor implementação, baseado na figura 3.
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

    -- Definicao da constante global
    constant RISCV_Data_Width : natural := 32;

    -- Declaracao das funcoes 
    -- i - to_uinteger 
    function to_uinteger(i0 : BIT_VECTOR) return natural;
    
    -- ii - +
    function "+" (left, right : BIT_VECTOR) return bit_vector;

    -- iii - -
    function "-" (left, right : BIT_VECTOR) return bit_vector;

    -- Definicao de componentes 
    -- Componente Mux2
    component mux2 is
        port(
		d0, d1:         in 		    BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		s: 		        in 		    BIT;
		y: 		        out 	    BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component mux2;

    -- Componente Mux3 
    component mux3 is
        port(
		d0, d1, d2:     in          BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		s:              in          BIT_VECTOR(1 downto 0);
		y:              out         BIT_VECTOR(RISCV_Data_Width- 1 downto 0)
	    );
    end component mux3;

    -- Componente flopr
    component flopr is
        port(
		clk, reset:     in          BIT;
		d:              in          BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		q:              out         BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component flopr;

    -- Componente flopenr
    component flopenr is
        port(
		clk, reset, en: in          BIT;
		d:              in          BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		q:              out         BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	    );
    end component flopenr;

    -- Componente extend
    component extend is
        port(
		instr:          in          BIT_VECTOR(31 downto 7);
		immsrc:         in          BIT_VECTOR(1 downto 0);
		immext:         out         BIT_VECTOR(31 downto 0)
	    );
    end component extend;

    -- Componente alu
    component alu is
    	port(
		a, b:           in          BIT_VECTOR(RISCV_Data_Width downto 0);
		ALUControl:     in          BIT_VECTOR(2 downto 0);
		ALUResult:      out         BIT_VECTOR(RISCV_Data_Width downto 0);
		--Overflow: out BIT;
		Zero: out BIT
	);
    end component alu;

end package riscv_pkg;

package body riscv_pkg is  -- Corpo do pacote para a simulacao

    -- i - function to_uinteger

    function to_uinteger(i0 : BIT_VECTOR) return natural is 

        variable result_integer : natural;

        begin 
            result_integer := to_integer(unsigned(to_stdlogicvector(i0)));
        return result_integer;
    end to_uinteger; 

    -- ii - function "+"

    function "+"(left, right: bit_vector) return bit_vector is

        variable sum : bit_vector(left'length downto 0);

        begin
            sum := ('0' & left) + ('0' & right);
        return sum;
    end function "+";

    -- iii - funcion "-" por complemento de 2 usando "+" 

    function "-" (left, right: bit_vector) return bit_vector is

        variable sub : bit_vector(left'length - 1 downto 0);
    
        begin
            sub := (not right) + "1";          
        return  "+"(left , sub); 
    end function "-";

end package body riscv_pkg;