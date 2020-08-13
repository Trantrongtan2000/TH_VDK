#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#INT_TIMER1
int8 dv,chuc,dem;
int8 den[9]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
const int8 led[10]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};
void qled()
{  
   output_low(pin_D3);
   output_low(pin_D2);
   output_low(pin_D1);
   output_high(pin_D0);
   output_b(led[chuc]);
   delay_ms(3);
   output_high(pin_D1);
   output_high(pin_D2);
   output_high(pin_D3);

   output_low(pin_D3);
   output_low(pin_D1);
   output_low(pin_D0);
   output_high(pin_D2);
   output_b(led[dv]);
   delay_ms(3);
   output_high(pin_D0);
   output_high(pin_D1);
   output_high(pin_D2);
   
   output_low(pin_D0);
   output_low(pin_D1);
   output_low(pin_D2);
   output_high(pin_D3);
   output_b(0xe0);
   delay_ms(3);
   output_high(pin_D2);
   output_high(pin_D0);
   output_high(pin_D1);
   
   output_low(pin_D0);
   output_low(pin_D2);
   output_low(pin_D3);
   output_high(pin_D1);
   output_b(0x63);
   delay_ms(3);
   output_high(pin_D2);
   output_high(pin_D0);
   output_high(pin_D3);

}
void main(void)
{ 
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
for (int8 dem=0; dem<50;dem++)
   {
   dv=dem%10;
   chuc=dem/10;
   for(int8 i=0;i<9;i++)
   output_c(den[i]);delay_ms(300);
   qled();
   }
}
