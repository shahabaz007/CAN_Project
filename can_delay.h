// can delay
void can_delay(unsigned int n)

{

	T0PR=60000-1;

	T0TCR=0X01;

	while(T0TC<n);

	T0TCR=0X03;

	T0TCR=0X0;

}
