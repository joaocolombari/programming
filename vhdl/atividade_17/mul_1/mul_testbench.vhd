library work;
use work.riscv_pkg.all;

entity mul_tb is
end entity mul_tb;

architecture sim of mul_tb is
    constant Width : natural := 32;

    signal a, b    : bit_vector(Width - 1 downto 0);
    signal y       : bit_vector(2 * Width - 1 downto 0);

begin
    mul_proc: process
    begin
        -- 1111111111111111
        -- 0000000000000000

        -- Test Case 1: 3 * 3
        a <= "00000000000000000000000000000011";
        b <= "00000000000000000000000000000011";
        wait for 10 ns;
        assert y = "0000000000000000000000000000000000000000000000000000000000001001" report "Test Case 1 failed" severity error;

        -- Test Case 1: 3 * -3
        a <= "00000000000000000000000000000011";
        b <= "11111111111111111111111111111101";
        wait for 10 ns;
        assert y = "1111111111111111111111111111111111111111111111111111111111110111" report "Test Case 1 failed" severity error;

        -- Test Case 1: -3 * 3
        a <= "11111111111111111111111111111101";
        b <= "00000000000000000000000000000011";
        wait for 10 ns;
        assert y = "1111111111111111111111111111111111111111111111111111111111110111" report "Test Case 1 failed" severity error;

        -- Test Case 1: -3 * 3
        a <= "11111111111111111111111111111101";
        b <= "11111111111111111111111111111101";
        wait for 10 ns;
        assert y = "0000000000000000000000000000000000000000000000000000000000001001" report "Test Case 1 failed" severity error;

        wait;
    end process mul_proc;

    -- Instantiate the mul component
    mul_inst : mul port map (a => a, b => b, y => y);

end architecture sim;
