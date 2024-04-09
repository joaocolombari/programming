## Activity Statement 

The seventeenth activity was to modify the implemented architecture by adding the MULDIV instruction for the multiplication of two 32-bit signed values. The MUL function performs multiplication of XLEN bits by XLEN bits and stores the least significant XLEN bits in the destination register. MULH, MULHU, and MULHSU perform the same multiplication but return the most significant XLEN bits of the complete 2xXLEN bits product for signed x signed, unsigned x unsigned, and signed x unsigned multiplication, respectively [1].

In the following table, the instruction format for MULDIV is presented, and in next one, the corresponding opcodes are provided.

| funct7 |  rs2   |  rs1   | funct3 |   rd   | opcode |
|--------|--------|--------|--------|--------|--------|
| 31-25  | 24-20  | 19-15  | 14-12  | 11-7   |  6-0   |

| **Opcode** | **Funct7** | **Funct3** | **Instruction** |
|------------|------------|------------|------------------|
| 0110011    | 0000001    | 000        | MUL              |
| 0110011    | 0000001    | 001        | MULH             |
| 0110011    | 0000001    | 010        | MULHSU           |
| 0110011    | 0000001    | 011        | MULHU            |
| 0110011    | 0000001    | 100        | DIV              |
| 0110011    | 0000001    | 101        | DIVU             |
| 0110011    | 0000001    | 110        | REM              |
| 0110011    | 0000001    | 111        | REMU             |

### Development 

The resolution of this exercise was intended to be done using the extended resolution of Exercise 7.6.6 of [2], which statement is the one available in tghe following figure. Or, directly translating - "The multiplication operation between two positive integers can be implemented by a set of full adders. Figure 7.6.5 illustrates the case of a 3-bit multiplier, where "a" and "b" are the input signals, and "p" is the output signal. Provide a description of the proposed multiplier".

<p align="center">
 
  <img src="https://github.com/joaocolombari/Projeto2023/assets/105496210/873b268d-2382-4af3-a36f-f5e40b493f69" width="600">

</p>

Based on such exercise, the professor sugested a method for expanding the solution in order to acheive a parameterized solution, which was very helpfull. Together with this solution, the author implemented the full adder, which is available in this directory as "fulladder.vhd" and instantiated it within the mul architecture, just as it is shown in the exercise and the mul was successfully implemented. This first version is available here as "mul_1.vhd" together with a testbench, named "mul_1_testbench.vhd".

The testbench tests for unsigned x unsigned, unsigned  x signed, signed x unsigned and signed x signed in the following way.

```
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
```

Running a ModelSim simulation, it can be seen that tests one and two are successful and three and four are not. 

Test 3 returns:

```
0000000000000000000000000000001011111111111111111111111111110111
```

And test 4 returns:

```
1111111111111111111111111111110100000000000000000000000000001001
```

Thus only the 32 most significant bits are right. The author tryied several forms to fix this issue but was unsuccessful. Nevertheless, the mul can also work. Once signed x unsigned equals unsigned x signed, and signed x signed equals unsigned x unsigned, the fix can be only a matter of switching and unsigning numbers, and this last one was already implemented as a function in the package. 




### References 

[1] https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf

[2] Amore, R., "VHDL - Descrição e Síntese de Circuitos Digitais", LTC, 2012. 
