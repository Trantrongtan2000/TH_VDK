#include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
#INT_TIMER1
void qled()
{
   output_d(0xff);
   output_b(0x91);output_low(PIN_D3);delay_ms(3);
   output_d(0xff);
   output_b(0x61);output_low(PIN_D2);delay_ms(3);
   output_d(0xff);
   output_b(0xe3);output_low(PIN_D1);delay_ms(3);
   output_d(0xff);
   output_b(0x31);output_low(PIN_D0);delay_ms(3);
}
void main(void)
{ 
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER1);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
while(1);
}
