#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#include <lcd.c>
#define SW1 PIN_C3
#define SW2 PIN_C4
void main(void)
{ 
int8 SW=0;                               
int8 pt=0;
int8 giay=0;
int8 dem=0;
lcd_init();
lcd_gotoxy(1,1);
printf(lcd_putc,"DONG HO DEM GIAY");
while (TRUE)
{ 
   lcd_gotoxy(4,2);
   printf(lcd_putc,"%02u:%02u",giay,pt);
if(!input(SW1)) SW=1;
while(!input(SW2))
{
   SW=2;
   delay_ms(100);
   dem++;
   if(dem>50)
      {
         pt=0;giay=0;
         lcd_gotoxy(4,2);
         printf(lcd_putc,"%02u:%02u",giay,pt);
      }
}
switch(SW)
{
case 1:
{  
   {
   delay_ms(10);pt++;
   if(pt==100){pt=0;giay++;}
   lcd_gotoxy(4,2);
   printf(lcd_putc,"%02u:%02u",giay,pt);
   break;
   }
}

case 2:
{dem=0;
break;
}
}
}
}
