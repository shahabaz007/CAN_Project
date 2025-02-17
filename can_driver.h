// can driver
void can_init(void)
{
PINSEL1|=0x00014000;//P0.23-->RD2 & P0.24-->TD2

VPBDIV=1; //PCLK=60MHz

C2MOD=0x1; //CAN1 into Reset  Mode 

AFMR=0x2; //accept all receiving messages(data/remote)

C2BTR=0x001C001D; //B125Kbps @ PLCK=60MHz

C2MOD=0x0; //CAN1 into Normal Mode
}

void can_tx(c2 m1)
{
C2TID1=m1.id;

C2TFI1=(m1.dlc<<16);	

if(m1.rtr==0) //if data frame

{

	C2TFI1&=~(1<<30);//RTR=0

	C2TDA1=m1.byteA; //lower 4bytes of data

	C2TDB1=m1.byteB; //upper 4bytes of data

}

else
{

	C2TFI1|=(1<<30); //RTR=1  //extended frame

}

C2CMR=(1<<0)|(1<<5);//Start Xmission & select Tx Buf1

while((C2GSR&(1<<3))==0);//wait for data Xmission.
}

void can_rx(c2 *m1)
{
while((C2GSR&0x1)==0);

m1->id=C2RID;

m1->dlc=(C2RFS>>16)&0xF;

m1->rtr=(C2RFS>>30)&0x1;

if(m1->rtr==0) //if data frame

{
	m1->byteA=C2RDA;

	m1->byteB=C2RDB;

}

C2CMR=(1<<2);//free receiver buffer(imp)
}
