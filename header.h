#define sw1 14

#define sw2 15

#define sw3 16
typedef struct CAN2
{
unsigned int id;
unsigned int rtr;
unsigned int dlc;
unsigned int byteA;
unsigned int byteB;
}c2;
void can_init(void);
void can_tx(c2 m1);
void can_rx(c2 *m1);
void can_delay(unsigned int);

