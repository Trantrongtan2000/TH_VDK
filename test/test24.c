#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#include <lcd.c>
#define SW1 PIN_C3
#define SW2 PIN_C4
void main(void)
{ int8 SW=0;
lcd_init;
lcd_gotoxy(1,1);
printf(lcd_putc,"DONG HO DEM GIAY");
while (TRUE)
{lcd_init();
if(!input(SW1)) SW=1;
if(!input(SW2)) SW=2;
switch(SW)
{case 1: {
int8 giay=0;
int8 phantram=0;
while(1)
{
while(phantram<1000)
{
lcd_gotoxy(4,2);
printf(lcd_putc,"%02u:%02u",giay,phantram);
delay_ms(1);
phantram++
}
lcd_gotoxy(4,2);
printf(lcd_putc,"%02u:%02u",giay,phantram);
delay_ms(1000);
giay++
}
}

SW=0;break;}
case 2:{
lcd_gotoxy(4,2);
printf(lcd_putc,"HUTECH");
delay_ms(300);
SW=0;break;}}
}
}

