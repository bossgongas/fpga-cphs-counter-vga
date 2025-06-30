/*
 * exc2.c
 *
 *  Created on: 02/10/2023
 *      Author: uc2020238997
 */
/*
 * exc1.c
 *
 *  Created on: 27/09/2023
 *      Author: uc2020238997
 */
#include "system.h"
#include "stdio.h" //FOR DEBUG ONLY
#include "altera_avalon_pio_regs.h"



const unsigned char dec_encoding[10] = {
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
        byte1 = count%10;
        byte2 = (count / 10) %10;
        byte3 = (count / 100) %10;
        byte4 = (count / 1000) %10;

		//print to debug
        printf("%d - ", count);

        // byte to - hex digit
        char decDigit1 = dec_encoding[byte1];
        char decDigit2 = dec_encoding[byte2];
        char decDigit3 = dec_encoding[byte3];
        char decDigit4 = dec_encoding[byte4];

        // Display the 4-digit hexadecimal count on 7-segment displays
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_0_BASE, decDigit1);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_1_BASE, decDigit2);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_2_BASE, decDigit3);
        IOWR_ALTERA_AVALON_PIO_DATA(HEX_3_BASE, decDigit4);

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







