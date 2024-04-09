//
// iCE40 Configuration Pseudo-code
//
void Config_iCE40 (type, file)
{
    // Open Hex File early to avoid clock delay later
    file_pointer = fopen(file);// Open bin file

    /*
    Preciso definir:
        - SPI_SS
        - CRESET
        - SPI_CLK
        - Tem que ver o que e esse L1k etc..
        - 

    */

    // Reset the iCE40 Device
    Set_Port(SPI_SS, false);            // Set SPI_SS low 
    Set_Port(CRESET, false);            // Set CRESET low
    Set_Port(SPI_CLK, true);            // Set SPI_CLK high 
    nSec_Delay(200);                    // Delay minimum 200 nsec
    Set_Port(CRESET, true);             // Set CRESET high

    if (type == L1K or L4K)
    {
        uSec_Delay(800);                // Delay 800 usec if L1K,L4K 
    else if (type == L8K)
        uSec_Delay(1200);               // Delay 1200 usec for L8K 
    };

    Set_Port(SPI_SS, true);             // Set SPI_SS high
    Send_Clocks (8);                    // Send 8 clocks
    Set_Port(SPI_SS, false);            // Set SPI_SS low

    // Send data from bin file
    Send_File(file_pointer);            // Send bin file Send_Clocks (100);// Send 100 clocks

    // Verify successful configuration
    set_Port(SPI_SS,true);              // Set SPI_SS high
    
    if (Get_Port(CDONE))
    {
        Return PASS;                    // PASS if CDONE is true else
        Return FAIL;                    // FAIL if CDONE is false
    };
}

// Clock Generation 10MHz

void Send_Clocks(num_clocks)
{
    for (i = 0; i < num_clocks; i++)
    {
    Set_Port(SPI_CLOCK, false);         // Set SPI_CLK low 
    nSec_Delay(50);                     // Delay 50 nsec
    Set_Port(SPI_CLOCK, true);          // Set SPI_CLK high 
    nSec_Delay(50);                     // Delay 50 nsec
    };
}

// Send Data from file

void Send_File(file_pointer)
{
    byte = getc(file_pointer);          // Read first byte from file while (byte != EOF)
    Send_Byte (byte);                   // Send data byte
    byte = getc(file_pointer);          // read next byte from file
};