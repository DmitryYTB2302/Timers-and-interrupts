#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
unsigned char i;
void timer_set(void)
{
  TCCR1B |= (1<<WGM12); 
  TIMSK1 |= (1<<OCIE1B); 
  OCR1B = OCR1A = 30000; 
  TCCR1B |= (1<<CS12);
}
//--------------------------------------------
ISR (TIMER1_COMPB_vect)
{
  if(i>=8){ i=0; PORTD = 0;}
  PORTD =(1<<i);
  i++;
}
//--------------------------------------------
int main(void)
{
  timer_set();
  DDRD = 0xFF;
  sei();
  while(1){
    
  }
}
