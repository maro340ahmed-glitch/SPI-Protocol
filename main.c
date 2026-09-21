

#include <xc.h>
#include "BIT_MATH.h"
#include "SPI.h"
#include "STD_TYPES.h"
#include "avr/io.h"


int main(void)
{
	SPI_masterInit();
	
	
    while(1)
    {
		SPI_transmit('A');
        
		
    }
}