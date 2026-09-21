#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "STD_TYPES.h"

void SPI_masterInit(void);
void SPI_slaveInit(void);


u8 SPI_transmit(u8 data);
u8 SPI_receive(void);

#endif /* SPI_H_ */