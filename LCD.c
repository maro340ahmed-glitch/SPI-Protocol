#include "GPIO_STD_TYPES.h"
#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include "LCD.h"
#include <util/delay.h>

void LCD_Init(void) {
    GPIO_SetPIN_Direction(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
    GPIO_SetPIN_Direction(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);
    GPIO_SetPIN_Direction(LCD_DATA_PORT, PIN2, OUTPUT);
    GPIO_SetPIN_Direction(LCD_DATA_PORT, PIN3, OUTPUT);
    GPIO_SetPIN_Direction(LCD_DATA_PORT, PIN4, OUTPUT);
    GPIO_SetPIN_Direction(LCD_DATA_PORT, PIN5, OUTPUT);
    
    _delay_ms(40);
    LCD_SendCommand(0x02);
    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x01);
    LCD_SendCommand(0x06);
}

void LCD_SendCommand(u8 cmd) {
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN2, GET_BIT(cmd, 4));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN3, GET_BIT(cmd, 5));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN4, GET_BIT(cmd, 6));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN5, GET_BIT(cmd, 7));
    
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN2, GET_BIT(cmd, 0));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN3, GET_BIT(cmd, 1));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN4, GET_BIT(cmd, 2));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN5, GET_BIT(cmd, 3));
    
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    _delay_ms(2);
}

void LCD_SendChar(u8 data) {
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN2, GET_BIT(data, 4));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN3, GET_BIT(data, 5));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN4, GET_BIT(data, 6));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN5, GET_BIT(data, 7));
    
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN2, GET_BIT(data, 0));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN3, GET_BIT(data, 1));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN4, GET_BIT(data, 2));
    GPIO_SetPIN_Value(LCD_DATA_PORT, PIN5, GET_BIT(data, 3));
    
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    _delay_ms(2);
}

void LCD_SendString(const char* str) {
    while(*str) LCD_SendChar(*str++);
}

void LCD_Clear(void) {
    LCD_SendCommand(0x01);
}
