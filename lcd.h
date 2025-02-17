//lcd program
#include <LPC21XX.H>
//#include "delay.h"
# define rs 1<<17
# define e 1<<19
# define rw 1<<18
# define lcd_p 0xff<<16

void lcd_command(unsigned char cmd)
{
	IOCLR1|=lcd_p;
	IOSET1|= (cmd&0xf0)<<16;
	IOCLR1|= rs;
	IOCLR1|=rw;
	IOSET1|= e;
	can_delay(2);
	IOCLR1|= e;

	IOCLR1|=lcd_p;
	IOSET1|= (cmd&0x0f)<<20;
	IOCLR1|= rs;
	IOCLR1|=rw;
	IOSET1|= e;
	can_delay(2);
	IOCLR1|= e;

}

void lcd_data(unsigned char c)
{
	IOCLR1|=lcd_p;
	IOSET1|= (c&0xf0)<<16;
	IOSET1|= rs;
	IOCLR1|=rw;
	IOSET1|= e;
	can_delay(2);
	IOCLR1|= e;

	IOCLR1|=lcd_p;
	IOSET1|= (c&0x0f)<<20;
	IOSET1|= rs;
	IOCLR1|=rw;
	IOSET1|= e;
	can_delay(2);
	IOCLR1|= e;

}

void lcd_str(unsigned char *s)
{
	while(*s)
	{
		lcd_data(*s++);
	}
}


void lcd_init(void)
{
	PINSEL2 =0X00000000;
	IODIR1 = lcd_p|rs|e|rw;
	lcd_command(0x01);
	lcd_command(0x02);
	lcd_command(0x0c);
	lcd_command(0x28);
	lcd_command(0x80);
}
void lcd_integer( int n)
{
	int arr[5],i=0;

	if(n==0)

	{

		lcd_data('0');

	}

	else

	{

		if(n<0)

		{

			lcd_data('-');

			n=-n;

		}

		while(n>0)

		{

			arr[i++]=n%10;

			n=n/10;

		}

		for(--i;i>=0;i--)

		{

			lcd_data(arr[i]+48);

		}

	}

}
void lcd_float(float f)
{
	unsigned int num;
	num=f;
	lcd_integer(num);
	lcd_data('.');
	num=(f-num)*100;
	lcd_integer(num);
}

