#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
int8 dv,chuc,dem;
int8 den[9]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
const int8 led[10]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};
void dl_ms(int16 x)
{for(int16 j=0;j<x;j++) delay_us(1000);
}
#INT_TIMER1
void qled()
{
   dv=dem%10;
   chuc=dem/10;
   
   output_d(0xff);
   output_b(0x63);
   output_low(pin_D3);
   delay_ms(3);
   
   output_d(0xff);
   output_b(0xe0);
   output_low(pin_D2);
   delay_ms(3);
   
   output_d(0xff);
   output_b(led[chuc]);
   output_low(pin_D1);
   delay_ms(3);
   
   output_d(0xff);
   output_b(led[dv]);
   output_low(pin_D0);
   delay_ms(3);
}
void main(void)
{ 
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
while(dem<50)
{
for(int8 t=0;t<9;t++)
{
   output_c(den[t]);
  dl_ms(300);
}
   dem=dem+1;

}

} 
