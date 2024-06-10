
//******BarberShop.cpp**********

#include<iostream.h>
#include<stdio.h   >
#include<dos.h     >
#include<process.h >
#include<conio.h   >
#include<stdlib.h  >
#include<graphics.h>

//*********Customer Structure****************
struct Customer
	{
	char	customerName[20];
	int		barberID;
	int		serviceID;
	};
//*******End Customer Structure**************
#include<CQueue.cpp>						//contain Circular Queue data used as sofa in simulation
#include<Barber.cpp>						//Contain Barber and Customer data



void	barberSimulation();
int 	barberChoice();
int 	serviceChoice();
void	drawShop();

void main()
	{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	drawShop();
	barberSimulation();
	getch();
	}
//............................................................
int	barberChoice()
	{
	char ch = '1';
	do {
		outtextxy(2, 405, "Please choose your favourate barber");
		outtextxy(2, 415, "0. Mr. Jamil");
		outtextxy(2, 425, "1. Mr. Hassan");
		outtextxy(2, 435, "2. Mr. Zubair");
		outtextxy(2, 445, "3. Mr. Firoz");
		ch = getch();
		}while(!(ch >='0' && ch<='3'));
	setcolor(0);
	outtextxy(2, 405, "Please choose your favourate barber");
	outtextxy(2, 415, "0. Mr. Jamil");
	outtextxy(2, 425, "1. Mr. Hassan");
	outtextxy(2, 435, "2. Mr. Zubair");
	outtextxy(2, 445, "3. Mr. Firoz");
	setcolor(GREEN);
	return ch - '0';
	}
//............................................................
int serviceChoice()
	{
	char ch = '1';
	do {
		outtextxy(2, 405, "Please choose your service");
		outtextxy(2, 415, "0. Hair Cut 60");
		outtextxy(2, 425, "1. Shave for Rs 20");
		outtextxy(2, 435, "2. Both for Rs 80");
		ch = getch();
		}while(!(ch >='0' && ch<='2'));

	setcolor(0);
	outtextxy(2, 405, "Please choose your service");
	outtextxy(2, 415, "0. Hair Cut 60");
	outtextxy(2, 425, "1. Shave for Rs 20");
	outtextxy(2, 435, "2. Both for Rs 80");

	setcolor(GREEN);
	return ch - '0';
	}
//............................................................
void	drawShop()
	{
	rectangle(1, 1, 639, 400);

	rectangle(41,  41, 120, 80);					//Chair 1
	rectangle(201, 41, 280, 80);					//Chair 2
	rectangle(361, 41, 440, 80);					//Chair 3
	rectangle(521, 41, 600, 80);					//Chair 4

	rectangle(41,  141, 120, 300);					//Sofa 1
	rectangle(201, 141, 280, 300);					//Sofa 2
	rectangle(361, 141, 440, 300);					//Sofa 3
	rectangle(521, 141, 600, 300);					//Sofa 4

	rectangle(1, 400, 639, 479);
	}
//............................................................
void clearline(int y)
	{
	char ch[2] = {219};
	setcolor(0);
	for(int i=0; i<640; i++)
		outtextxy(i, y, ch);
	setcolor(GREEN);
	}
//.............................................................
void barberSimulation()
	{
	int randNum;
	setcolor(GREEN);
	Customer myCustomer;
	Barber myBarber[4];

	myBarber[0].setBarberName("Jamil");
	myBarber[1].setBarberName("Hassan");
	myBarber[2].setBarberName("Zubair");
	myBarber[3].setBarberName("Firoz");

	myBarber[0].setBarberPos(41, 90);
	myBarber[1].setBarberPos(201, 90);
	myBarber[2].setBarberPos(361, 90);
	myBarber[3].setBarberPos(521, 90);

	outtextxy(myBarber[0].X, myBarber[0].Y, myBarber[0].barberName);
	outtextxy(myBarber[1].X, myBarber[1].Y, myBarber[1].barberName);
	outtextxy(myBarber[2].X, myBarber[2].Y, myBarber[2].barberName);
	outtextxy(myBarber[3].X, myBarber[3].Y, myBarber[3].barberName);
	while(1)
		{
		randNum = rand()%4;						//choose random index of barber object
		switch(rand()%5+1)
			{
			case 1:								//Customer entered the shop
				clearline(405);
				outtextxy(2, 405, "One Customer entered the shop ");
				delay(2500);
				clearline(405);
				char nam[2];
				char check[5] = "exit";
				int valid =0;
				outtextxy(2, 405, "Customer Name: ");
				for(int i=0; myCustomer.customerName[i] != '\r'; i++)
					{
					myCustomer.customerName[i] = getch();
					if(myCustomer.customerName[i] == '\r')
						{
						if(valid==4 && i==4)
							exit(0);
						myCustomer.customerName[i] = '\0';
						break;
						}
					if(myCustomer.customerName[i] == check[i])
						valid++;
					sprintf(nam, "%c", myCustomer.customerName[i]);
					outtextxy(160 + i*10, 405, nam);
					}
				clearline(405);
				myCustomer.barberID = barberChoice();
				myCustomer.serviceID = serviceChoice();
				myBarber[myCustomer.barberID].customerIn(myCustomer);
				break;
			case 2:								//Customer to serve
				myBarber[randNum].customerToServe(myBarber[randNum].barberName, randNum);
				break;
			case 3:
				myBarber[randNum].customerServed();
				break;
			case 4:
				myBarber[randNum].barberTimeOut();
				break;
			case 5:
				myBarber[randNum].barberIn();
				break;
			default:
				cout<<"Invalid number returned by rand()";
			}
		}
	}
