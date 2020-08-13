 #include <16F877A.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP
#use delay(clock=8M)
void delay400ms()
{
   Setup_timer_0(RTCC_INTERNAL|RTCC_DIV_4);
   for(int16 i=0;i<800;i++)
   {
   Setup_timer_0(0);
   while(get_timer0()<250);
   }
}
void main(void)
{ 
While(1)
   {
   output_c(0x01);
   delay400ms();
   output_c(0x00);
   delay400ms();
   }
}
