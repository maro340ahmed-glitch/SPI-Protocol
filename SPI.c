#include "avr/io.h"
#include "SPI.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void SPI_masterInit()
{
	
	SET_BIT(DDRB,3); // MOSI
	SET_BIT(DDRB,5); // SCK
	SET_BIT(DDRB,2); // SS
	CLR_BIT(DDRB,4); // MISO
	
	
	
	SET_BIT(PORTB , 2);
	
	// Registers 
	
	CLR_BIT(SPCR,7); // Interrupt Enable
	SET_BIT(SPCR,6); // SPI Enable
	CLR_BIT(SPCR,5); // Data Order (from LSB)
	SET_BIT(SPCR,4); // MASTER 
	// Clock Polarity 
	CLR_BIT(SPCR,3); // Clock Polarity
	CLR_BIT(SPCR,2); // Clock Phase
	// SPI Clock Rate Select
	SET_BIT(SPCR,1); 
	CLR_BIT(SPCR,0); 
	
	
	

	


}



void SPI_slaveInit()
{
	
	CLR_BIT(DDRB,3); // MOSI
	CLR_BIT(DDRB,5); // SCK
	CLR_BIT(DDRB,2); // SS
	SET_BIT(DDRB,4); // MISO
	
	
	// Registers
	
	CLR_BIT(SPCR,7); // Interrupt Enable
	SET_BIT(SPCR,6); // SPI Enable
	SET_BIT(SPCR,5); // Data Order (from LSB)
	CLR_BIT(SPCR,4); // SLAVE
	// Clock Polarity
	SET_BIT(SPCR,3); // Clock Polarity
	SET_BIT(SPCR,2); // Clock Phase
	
}





u8 SPI_transmit(u8 data)
{
	SPDR = data;

	return SPI_receive();
	
	

}


u8 SPI_receive()
{
	while (GET_BIT(SPSR,7) == 0);
	return SPDR;
}