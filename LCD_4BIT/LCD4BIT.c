

unsigned char name[20] = {"this is rahul yadav"};
void lcdcmd(unsigned  char c)
{
  PORTD = ((PORTD & 0x0f) | (c & 0xf0));
  PORTB &= (~(1 << PB0)); //rs=0
  PORTB |= (1 << PB1); //en=1
  _delay_ms(50);
  PORTB &= (~(1 << PB1)); //en=0
  _delay_ms(50);
  PORTD = ((PORTD & 0X0F) | (c << 4));
  PORTB |= (1 << PB1); //en=1
  _delay_ms(50);
  PORTB &= (~(1 << PB1)); //en=0
  _delay_ms(50);

}
void lcddata(unsigned char a)
{

  PORTD = ((PORTD & 0x0f) | (a & 0xf0));
  PORTB |= (1 << PB0); //rs=1
  PORTB |= (1 << PB1); //en=1
  _delay_ms(50);
  PORTB &= (~(1 << PB1)); //en=0
  _delay_ms(50);
  PORTD = ((PORTD & 0X0F) | (a << 4));
  PORTB |= (1 << PB1); //en=1
  _delay_ms(50);
  PORTB &= (~(1 << PB1)); //en=0
  _delay_ms(50);

}

int main()
{
  unsigned char j, k;
  DDRD |= 0XF0;
  DDRB |= 0X03;
  //DDRD &= ~0xFF;
  lcdcmd(0x33);
  lcdcmd(0x32);  /* Send for 4 bit initialization of LCD  */
  lcdcmd(0x28);  /* 2 line, 5*7 matrix in 4-bit mode */
  lcdcmd(0x0c);  /* Display on cursor off */
  lcdcmd(0x06);  /* Increment cursor (shift cursor to right) */
  lcdcmd(0x01);  /* Clear display screen */

  while (1)
  {
    for (j = 0; j < 20; j++)
    {
      lcdcmd(0x80);
      for (k = j; k < j + 16; k++)
      {
        lcddata(name[k]);
      }
      _delay_ms(1);
    }
  }
}
