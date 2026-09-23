#ifndef LCD_H
#define LCD_H

#include "GPIO_interface.h"
#include "GPIO_STD_TYPES.h"

#define LCD_DATA_PORT GPIO_PORTD
#define LCD_CTRL_PORT GPIO_PORTD

#define LCD_RS_PIN PIN0
#define LCD_EN_PIN PIN1

void LCD_Init(void);
void LCD_SendCommand(u8 cmd);
void LCD_SendChar(u8 data);
void LCD_SendString(const char* str);
void LCD_Clear(void);

#endif

