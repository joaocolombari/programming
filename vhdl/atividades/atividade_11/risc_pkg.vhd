--
-- A décima primeira atividade é incluir o arquivo datapath.vhd ao projeto, defini-lo como 
-- toplevel, e realizar alterações na entidade datapath de forma a:
--
-- i) parametrizá-la em função de Width (da mesma forma que foi feito com a entidade flopr);
--
-- ii) incluir a solicitação de uso do pacote riscv_pkg, tornando visível todas as declarações;
--
-- iii) acrescentar ao pacote riscv_pkg a declaração de componente para a entidade datapath.
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
        generic (
            Width : natural := RISCV_Data_Width
        );
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
		instr:          in          BIT_VECTOR(RISCV_Data_Width - 1 downto 7);
		immsrc:         in          BIT_VECTOR(1 downto 0);
		immext:         out         BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
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

    component regfile is 
	port(
		clk: 			in 			BIT;
		we3: 			in 			BIT;
		a1, a2, a3: 	in 			BIT_VECTOR(4 downto 0);
		wd3: 			in 			BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		rd1, rd2: 		out 		BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	);
    end component regfile;

    component adder is
	port(
		a, b: 			in 			BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		y: 				out 		BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	);
    end component adder;

    component datapath is
	port(
		clk, reset: 	in 			BIT;
		ResultSrc: 		in 			BIT_VECTOR(1 downto 0);
		PCSrc, ALUSrc: 	in 			BIT;
		RegWrite: 		in 			BIT;
		ImmSrc: 		in 			BIT_VECTOR(1 downto 0);
		ALUControl: 	in 			BIT_VECTOR(2 downto 0);
		Zero: 			out 		BIT;
		PC: 			buffer 		BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		Instr: 			in 			BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		ALUResult, WriteData: 
						buffer 		BIT_VECTOR(RISCV_Data_Width - 1 downto 0);
		ReadData: 		in 			BIT_VECTOR(RISCV_Data_Width - 1 downto 0)
	);
    end component datapath;

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