#include <main.h>
#include <LCD.c>
#use standard_io(a)
#define USE_PORTB_LCD TRUE
void main(){
   SET_TRIS_A(0b00000011);
   LCD_INIT();
   LCD_PUTC("\f");
   output_high(PIN_A4);
   while(TRUE){     
      if (input_state(PIN_A0)==1){
         lcd_gotoxy(1,1);
         printf(lcd_putc, "Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Derecha");
         output_high(PIN_A2);
      }
      else if (input_state(PIN_A1)==1){
         lcd_gotoxy(1,1);
         printf(lcd_putc, "Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc, "Izquierda");
         output_high(PIN_A3);
      } 
      else{
         lcd_gotoxy(1,1);
         printf(lcd_putc, "\f Motor apagado");
         output_low(PIN_A2);
         output_low(PIN_A3);
         delay_ms(100);
      }  
   }
}
