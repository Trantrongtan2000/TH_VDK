#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#include <lcd.c>
#define SW1 PIN_C3
#define SW2 PIN_C4
void main(void)
{ int8 SW=0,set_val=0;
lcd_init();
lcd_gotoxy(5,1);
printf(lcd_putc,"Set value");
lcd_gotoxy(8,2);
printf(lcd_putc,"%03u",set_val);
while (TRUE)
{
if(!input(SW1)) SW=1; 
if(!input(SW2)) SW=2;
switch(SW)
{case 1: { if(set_val<200){
set_val=set_val+5;
lcd_gotoxy(8,2);
printf(lcd_putc,"%03u",set_val);
delay_ms(300);
SW=0;break;}}
case 2:{ if(set_val>0){
set_val=set_val-1;
lcd_gotoxy(8,2);
printf(lcd_putc,"%03u",set_val);
delay_ms(300);
SW=0;break;}}
}
}
}

