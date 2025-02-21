/*
 * LCD.h
 *
 * Created: 8/7/2024 4:32:03 PM
 *  Author: Farid
 */ 


#ifndef LCD_H_
#define LCD_H_
#define LCD_DATA_PORT PORTA
#define LCD_CTRL_PORT PORTB
#define RS_PIN PB2
#define RW_PIN PB5
#define E_PIN PB4

void LCD_Command (unsigned char x){
  LCD_DATA_PORT = x;
  LCD_CTRL_PORT &=~ (1 << RS_PIN);  // RS = 0 means command
  LCD_CTRL_PORT &=~ (1 << RW_PIN);  // RW = 0 means write
  LCD_CTRL_PORT |= (1 << E_PIN);    // E = 1 means enable high
  _delay_ms(1);
  LCD_CTRL_PORT &=~ (1 << E_PIN);   // E = 0 means enable low
  _delay_ms(1);
}

void LCD_Data_Char (unsigned char x){
  LCD_DATA_PORT = x;
  LCD_CTRL_PORT |= (1 << RS_PIN);   // RS = 1 means data
  LCD_CTRL_PORT &=~ (1 << RW_PIN);  // RW = 0 means write
  LCD_CTRL_PORT |= (1 << E_PIN);    // E = 1 means enable high
  _delay_ms(1);
  LCD_CTRL_PORT &=~ (1 << E_PIN);   // E = 0 means enable low
  _delay_ms(1);
}

void LCD_Data_String (const char *x){
  for(unsigned char i = 0; x[i]!='\0'; i++){
    LCD_Data_Char (x[i]);
    _delay_ms(10);
  }
}

void LCD_init(){
  DDRA = 0xff;
  DDRB |= (1 << RS_PIN) | (1 << RW_PIN) | (1 << E_PIN);
  _delay_ms(20);
  LCD_Command(0x38);
  LCD_Command(0x01);
  LCD_Command(0x0E);
  _delay_ms(20);
}

#endif /* LCD_H_ */