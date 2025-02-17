// CAN tx main node
#include <LPC21XX.H>
#include "header.h"
#include "lcd.h"
#include "can_driver.h"
#include "can_delay.h"
int main()
{
	int flag1=0,flag2=0,flag3=0;

	c2 m1;

	c2 m2;

	c2 m3;

	can_init();

	lcd_init();	

	lcd_command(0x82);

	lcd_str("Body Control ");
	lcd_command(0xc4);
	lcd_str("Module");
	
	m1.id=0x000001AF;

	m1.rtr=0;//data frame

	m1.dlc=4;

	m1.byteA=0xDDCCBAAA;//higher byte

 	m1.byteB=0;//lower byte


	m2.id=0x000001BF;

	m2.rtr=0;//data frame

	m2.dlc=4;

	m2.byteA=0xDDCCBAAA;//higher byte

    m2.byteB=0;//lower byte	 


	m3.id=0x000001CF;

	m3.rtr=0;//data frame

	m3.dlc=4;

	m3.byteA=0xDDCCBAAA;//higher byte

    m3.byteB=0;//lower byte	 


	while(1)

	{

		if(((IOPIN0>>sw1)&1)==0)

	  	{
			
			can_delay(1);
			can_tx(m1);
			
			if(flag1==0)

			{
				//m1.byteB=0x01;
				//can_tx(m1);
				lcd_command(0x01);

				lcd_str("LEFT INDIC. ON");

				flag1=1;

			}

			else

			{
				//m1.byteB=0x02;

				//can_tx(m1);

				lcd_command(0x01);

			   lcd_str("LEFT INDIC. OFF");

				flag1=0;

			}

			while(((IOPIN0>>sw1)&1)==0);     

	  }	

		if(((IOPIN0>>sw2)&1)==0)

	  {

			can_delay(1);

			can_tx(m2);

			if(flag2==0)

			{

				lcd_command(0x01);

				lcd_str("RIGHT INDIC. ON");

				flag2=1;

			}

			else

			{

			   	lcd_command(0x01);

				lcd_str("RIGHT INDIC. OFF");

				flag2=0;

			}

			while(((IOPIN0>>sw2)&1)==0);     

	  }	

		

		if(((IOPIN0>>sw3)&1)==0)

	  {

	        can_delay(1);

			can_tx(m3);

			if(flag3==0)

			{

				lcd_command(0x01);

				lcd_str("MOTOR ON");

				flag3=1;

			}

			else

			{

			  	lcd_command(0x01);

				lcd_str("MOTOR OFF");

				flag3=0;

			}

			while(((IOPIN0>>sw3)&1)==0);

		}

	}
}
