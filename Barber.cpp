
//bscs-notes.blogspot.com

//************Barber CLass******************
class Barber
	{
	private:
		int		barberflag;
		int		chairflag;
	public:
		char	barberName[12];
		Customer customerOnChair;
		CQueue	sofa;
		int		barberID;
		int     X;
		int		Y;

	public:
		int		customerIn(Customer myCustomer);
		int		barberTimeOut();
		int		barberIn();
		int		customerServed();
		int		customerToServe(char bName[], int barberID);
		void	setBarberPos(int x, int y);
		void	setBarberName(char name[]);
		void	setChair(int barberID);
		void 	setSofa(int barberID, int total);
				Barber();
	};
//************End Barber CLass***************

//**Barber CLass Member Function deffinitions***

//////////////////////////////////////////////
/////// set barber position function deffinition
void   Barber::setBarberPos(int x, int y)
	{
	X = x;
	Y = y;
	}
/////// end set barber position function deffinition

//////////////////////////////////////////////
/////// customer in function deffinition
void clearline(int y);
int Barber::customerIn(Customer myCustomer)
	{
	if(! sofa.isFull())						//if barber's sofa is not full
		{
		char msg[20];
		sofa.enqueue(myCustomer);
		setcolor(GREEN);
		setSofa(myCustomer.barberID, sofa.count);
		clearline(405);
		sprintf(msg,"Welcome %s", myCustomer.customerName);
		outtextxy(2, 405, msg);
		delay(2500);
		clearline(405);
		return 1;
		}
	else
		{
		clearline(405);
		outtextxy(2, 405, "1 customer entered the shop but shop is full");
		delay(2500);
		clearline(405);
		return 0;
		}
	}
/////// end customer in function deffinition

//////////////////////////////////////////////
/////// customer to serve function deffinition
int Barber::customerToServe(char bName[20], int barberID)
	{
	if(! sofa.isEmpty() && barberflag == 1 && chairflag ==0)	//if shop is not empty and
		{														//barber is in shop and chair is free
		setcolor(0);
		setSofa(barberID, sofa.count);
		setcolor(GREEN);
		char msg[40];
		customerOnChair = sofa.dequeue();
		sprintf(msg,"%s is now serving %s", bName, customerOnChair.customerName);
		outtextxy(2, 405, msg);
		delay(2000);
		clearline(405);
		outtextxy(2, 405, msg);
		chairflag = 1;

		setChair(barberID);
		setSofa(barberID, sofa.count);

		return 1;
		}
		else
			return 0;
	}
/////// end customer to serve function deffinition

void printCharges(Customer customerOnChair)
	{
	char msg[40];
		switch(customerOnChair.serviceID)
			{
			case 1:
				sprintf(msg, "Mr. %s your charger are Rs 60", customerOnChair.customerName);
				break;
			case 2:
				sprintf(msg, "Mr. %s your charger are Rs 20", customerOnChair.customerName);
				break;
			case 3:
				sprintf(msg, "Mr. %s your charger are Rs 80", customerOnChair.customerName);
				break;
			}
	outtextxy(2, 405, msg);
	delay(2500);
	clearline(405);
	}

//////////////////////////////////////////////
/////// customer served function deffinition
int Barber::customerServed()
	{
	if(barberflag == 1 && chairflag ==1)						//if sofa was not empty and
		{														//barber was in shop and chair was free
		setcolor(0);
		setChair(customerOnChair.barberID);
		setcolor(GREEN);
		char msg[40];
		sprintf(msg,"Mr. %s served %s", barberName, customerOnChair.customerName);
		outtextxy(2, 405, msg);
		delay(2500);
		clearline(405);
		printCharges(customerOnChair);

		chairflag = 0;
		outtextxy(2, 405, "Thanks! for visiting out shop.");
		delay(2500);
		clearline(405);
		return 1;
		}
	else
		return 0;
	}
/////// end customer served function deffinition

//////////////////////////////////////////////
/////// BARBER TIME OUT function deffinition
int Barber::barberTimeOut()
	{
	char msg[40];
	if(barberflag && chairflag != 1)												//if barber was in the shop
		{
		setcolor(0);
		outtextxy(X, Y, barberName);
		setcolor(RED);

		sprintf(msg, "Mr. %s timed out for lunch", barberName);
		outtextxy(2, 405, msg);
		delay(2000);
		clearline(405);
		barberflag = 0;
		setcolor(GREEN);
		return 1;
		}
	else
		return 0;
	}
/////// end BARBER TIME OUT function deffinition

//////////////////////////////////////////////
/////// BARBER IN function deffinition
int Barber::barberIn()
	{
	if(! barberflag)											//if barber is not in shop
		{
		setcolor(GREEN);
		outtextxy(X, Y, barberName);

		char msg[40];
		sprintf(msg, "Mr. %s returned to shop", barberName);

		outtextxy(2, 405, msg);
		delay(2000);
		clearline(405);
		barberflag = 1;
		return 1;
		}
	else
		return 0;
	}
/////// end BARBER IN function deffinition

//////////////////////////////////////////////
/////// BARBER CONSTRUCTOR deffinition
Barber::Barber()
	{
	barberflag = 1;
	chairflag  = 0;
	}
/////// end BARBER CONSTRUCTOR deffinition

//////////////////////////////////////////////
/////// Set Chair function deffinition
void	Barber::setChair(int barberID)
	{
	switch(barberID)
			{
			case 0:
				outtextxy(45, 45, customerOnChair.customerName);
				break;
			case 1:
				outtextxy(205, 45, customerOnChair.customerName);
				break;
			case 2:
				outtextxy(365, 45, customerOnChair.customerName);
				break;
			case 3:
				outtextxy(525, 45, customerOnChair.customerName);
				break;
			default:
				cout<<"invalid barber id for chair";
			}
	}
/////// end Chair function deffinition

//////////////////////////////////////////////
/////// Set Barber Name function deffinition
void	Barber::setBarberName(char name[])
	{
	for(int i=0; name[i] != '\0'; i++)
		barberName[i]= name[i];
	barberName[i]= '\0';
	}
/////// end Barber Name function deffinition

//////////////////////////////////////////////
/////// Set Sofa function deffinition
void Barber::setSofa(int barberID, int total)
	{
	switch(barberID)
		{
		case 0:
			for(int i=0; i<total; i++)
				outtextxy(45 , 160+35*i, sofa.cQueue[(sofa.front+1+i)%sofa.size].customerName);
			break;
		case 1:
			for(i=0; i<total; i++)
				outtextxy(205 , 160+35*i, sofa.cQueue[(sofa.front+1+i)%sofa.size].customerName);
			break;
		case 2:
			for(i=0; i<total; i++)
				outtextxy(365 , 160+35*i, sofa.cQueue[(sofa.front+1+i)%sofa.size].customerName);
			break;
		case 3:
			for(i=0; i<total; i++)
				outtextxy(525 , 160+35*i, sofa.cQueue[(sofa.front+1+i)%sofa.size].customerName);
			break;
		default:
			cout<<"Invalid barber choice!";
		}
	}
/////// end set Sofa function deffinition
