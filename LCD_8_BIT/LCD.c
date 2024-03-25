
unsigned char name[20]={"this is RAHUL YADAV"};
void lcdcmd(unsigned char c)
{
  PORTB&=(~(1<<PB0));//RS=0
  PORTD=c;
  PORTB|=(1<<PB1);//en=1
  _delay_ms(50);
  PORTB&=(~(1<<PB1));//EN=0
  _delay_ms(50);
}
void lcddata(unsigned char d)
{
  PORTB|=(1<<PB0);
  PORTD=d;
  PORTB|=(1<<PB1);
  _delay_ms(50);
  PORTB&=(~(1<<PB1));
  _delay_ms(50);
}

int main()
{
  unsigned char j,k;
  DDRD=0XFF;
  DDRB=0X03;
  lcdcmd(0x38);//2lines mode
  lcdcmd(0x0C);//clear
  lcdcmd(0X06);//DISPLAY ON,CURSOR BLINKING  
  lcdcmd(0x01); 
   while(1)
  {
    for(j=0;j<20;j++)
    {
      lcdcmd(0x80);
      for(k=j;k<j+16;k++)
      {
        lcddata(name[k]);
      }
      _delay_ms(1);
    }
  }
  
  
}
