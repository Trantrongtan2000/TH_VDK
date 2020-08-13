#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#include <lcd.c>
#define SW1 PIN_C3
#define SW2 PIN_C4
void main(void)
{ 
int8 SW=0;                               
int8 phut=0;
int8 gio=0;
int8 giay=0;
lcd_init();
lcd_gotoxy(4,1);
printf(lcd_putc,"DONG HO");
while (TRUE)
{ 
   if(!input(SW1)) {if(gio<=23){gio++;}else{gio=0;}}
   if(!input(SW2)) {if(phut>=59){gio++;phut=0;}else{phut++;}}
   delay_ms(100);giay++;
   if(giay==600){giay=0;phut++;}
   if(phut==60){phut=0;gio++;}
   if(gio==24){gio=0;}
   lcd_gotoxy(4,2);
   printf(lcd_putc,"%02u:%02u:%02u",gio,phut,giay);
}
}
