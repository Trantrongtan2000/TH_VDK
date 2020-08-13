#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#INT_TIMER0
int8 dv,chuc,tram,dem;
const int8 led[10]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};
void qled()
{
   dv=dem%10;
   chuc=dem%100/10;
   tram=dem/100;

   output_d(0xff);
   output_b(led[dv]);
   output_low(pin_D0);
   delay_ms(3);
   
   output_d(0xff);
   output_b(led[chuc]);
   output_low(pin_D1);
   delay_ms(3);
   
   output_d(0xff);
   output_b(led[tram]);
   output_low(pin_D2);
   delay_ms(3);
}
void main(void)
{ 
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER0);
setup_timer_0(RTCC_DIV_64|RTCC_INTERNAL);
while(1)
{
for(int16 i=0;i<2;i++)
{qled();}
dem=dem+1;
}
}
