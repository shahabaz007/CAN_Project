// can 3 receiver
#include<LPC21XX.H>
#include "can_delay.h"
#include "header.h"
#include "can_driver.h"
#define m1 1<<14
#define m2 1<<15
int flag=0;
int main()
{
c2 m3;
IODIR0|=m1|m2;
can_init();
while(1)
{
can_rx(&m3);
if((m3.id==0x000001CF)&&(m3.rtr==0))
{
if(flag==0)
{

IOSET0|=m1;
IOCLR0|=m2;
flag=1;
}
else
{
IOSET0|=m1|m2;
flag=0;
}
}

}
}
