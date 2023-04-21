#include <avr/io.h>
#define F_CPU 16000000 //частота кварца

void port_set()
{
  DDRD = 0b11111111;
  PORTD  = 255;
  TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);
}

void timer_set()
{
  TCCR1B = 0;
} 

void wait()
{
  TCNT1 = 0;
  while(TCNT1 < 5000){}
}

int main(void)
{
  timer_set();
  port_set();
  while(1)
  {
    PORTD = 0b10000000;
    wait(); 
    PORTD = 0b01000000;
    wait(); 
    PORTD = 0b00100000;
    wait(); 
    PORTD = 0b00010000;
    wait(); 
    PORTD = 0b00001000;
    wait();
    PORTD = 0b00000100;
    wait();
    PORTD = 0b00000010;
    wait();
    PORTD = 0b00000001;
    wait();
  }
}
