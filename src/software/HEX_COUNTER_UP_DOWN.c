/*
 * exc1.c
 *
 *  Created on: 27/09/2023
 *      Author: uc2020238997
 */
#include "system.h"
#include "stdio.h" //FOR DEBUG ONLY
#include "altera_avalon_pio_regs.h"



const unsigned char hex_encoding[16] = {
    // abcdefg (7-segment segments)
    0b1000000, // 0
	0b1111001, // 1
	0b0100100, // 2
	0b0110000, // 3
	0b0011001, // 4
	0b0010010, // 5
	0b0000010, // 6
	0b1111000, // 7
	0b0000000, // 8
	0b0010000, // 9
	0b0001000, // A
	0b0000011, // B
	0b1000110, // C
	0b0100001, // D
	0b0000110, // E
	0b0001110  // F
};

int main()
{
    // Initialize hardware peripherals and variables
    int count = 0;
    int direction = 1; // 1 for counting up, -1 for counting down
    int switches;
    int delay = 0;

    int byte1;
	int byte2;
	int byte3;
	int byte4;

    while (1)
    {
        // Read the state of the switches to control count direction
        switches = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE);

        // Check if a specific switch (e.g., switch 0) is set to change direction
        if (switches & 0x01)
        {
            direction = 1; // Count up
        }
        else
        {
            direction = -1; // Count down
        }

        // Update the counter based on direction
        count += direction;// i.e count + 1  ou count -1

        // split the number in 4 parts of 8 bits (byte each)
        byte1 = (count >> 12) & 0xF; // 0-255
        byte2 = (count >> 8) & 0xF;
        byte3 = (count >> 4) & 0xF;
        byte4 = count & 0xF;

		//print to debug
        printf("%d - ", count);

        // byte to - hex digit
        char hexDigit1 = hex_encoding[byte4];
        char hexDigit2 = hex_encoding[byte3];
        char hexDigit3 = hex_encoding[byte2];
        char hexDigit4 = hex_encoding[byte1];

        // Display the 4-digit hexadecimal count on 7-segment displays
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, hexDigit1);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, hexDigit2);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, hexDigit3);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE, hexDigit4);

        // Toggle activity LEDs
        IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, count);

        // Add a delay to control the counting speed
        delay = 0;
        while(delay < 2000000*2){
        		  delay++;
        };
    };

    return 0;
}



