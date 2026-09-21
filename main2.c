#include <xc.h>
#include "BIT_MATH.h"
#include "avr/io.h"
#include "SPI.h"
int main(void)
{
	SPI_slaveInit();
	
	SET_BIT(DDRB , 0);
	
    while(1)
    {
		u8 RecieveData = SPI_receive();
		
			if(RecieveData == 'A')
			{
				SET_BIT(PORTB ,0);
			}
			else
			{
				CLR_BIT(PORTB , 0);
			}
    }
}