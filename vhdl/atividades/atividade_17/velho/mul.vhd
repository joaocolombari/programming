--
-- Implementar a instrução MUL, fazendo uso da resolução expandida do exercício 7.6.6.
-- Apresentar código com comentários e simulação da instrução.
--
-- Este programa resolve o exercicio 7.6.6
--
--	Joao Victor Colombari Carlet - nro USP 5274502
--	
--	09 de Dezembro de 2023 
--

library work;
use work.riscv_pkg.all;
library ieee;
use ieee.std_logic_1164.all;

entity mul is 
    generic(
        Width : natural := 32
    );

    port(
        a, b:           in          BIT_VECTOR(Width - 1 downto 0);
        y:              out         BIT_VECTOR(2 * Width - 1 downto 0)
    );
end mul;

architecture multiplication of mul is   

    -- Vou definir um tipo para criar matrizes para armazenar os resultados das operacoes
    -- AND, os carrys e as saidas 
    type dataout is array (natural range <>) of std_logic_vector;

    signal AND_ARRAY:              dataout(Width - 1 downto 0)(Width - 1 downto 0);
    signal CARRY_ARRAY:            dataout(Width - 1 downto 1)(Width - 1 downto 0);
    signal OUTPUTS_ARRAY:          dataout(Width - 1 downto 1)(Width - 1 downto 0);
    signal adder_names:            names(Width - 1 downto 1)(Width - 1 downto 0);

begin

    -- Carregando a matriz AND_ARRAY com as portas AND
    process 
    begin 
    for i in 0 to Width - 1 loop 
        for j in 0 to Width - 1 loop 
            AND_VECTOR(i,j) <= a(j) AND b(i);
        end loop; 
    end loop; 
    end process;

    -- Instanciando os Somadores e conectando os sinais
    -- Adicionar os carry no ultimo adder de cada linha depois da primeira !!!!!!
    -- Acertar o numero de linhas tbm !!!!!!
    generate_adders_linha: for i in 0 to Width - 1 generate 
        generate_adders_coluna: for j in 0 to Width - 1 generate 
            generate_if_statement: if j = 0 generate 
                adder_i_j : fulladder port map (a => AND_ARRAY(i,j+1),b => AND_ARRAY(i+1,j), cin => '0', OUTPUTS_ARRAY(i+1,j), cout => CARRY_ARRAY(i+1,j));
            elsif j = Width - 1  
                adder_i_j : fulladder port map (a => '0',b => AND_ARRAY(i+1,j-1), cin => CARRY_ARRAY(i+1,j), OUTPUTS_ARRAY(i+1,j), cout => CARRY_ARRAY(i+1,j));
            else
                adder_i_j : fulladder port map (a => AND_ARRAY(i,j+1),b => AND_ARRAY(i+1,j-1), cin => CARRY_ARRAY(i+1,j), OUTPUTS_ARRAY(i+1,j), cout => CARRY_ARRAY(i+1,j));
            end generate generate_if_statement;
        end generate generate_adders_coluna; 
    end generate generate_adders_linha;
    
    -- Ligando as saidas dos somadores as saidas do mul
    -- Aqui vem mais codigo, ainda nao fiz

end multiplication;