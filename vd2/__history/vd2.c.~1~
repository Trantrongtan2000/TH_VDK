#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#include <lcd.c>
void main(void)
{
lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc,"Welcome to");
delay_ms(3);
lcd_gotoxy(1,2);
printf(lcd_putc,"*****HUTECH*****");
delay_ms(3);
while(1);
}

