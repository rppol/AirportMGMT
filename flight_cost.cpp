/*
Name : Rutik Pol
Roll no : 086
Batch : B2
*/


#include<iostream>
#include<ctime>
#include<process.h>

using namespace std;

class Date
{
	public:
	int d, m, y;
};

int countLeapYears(Date d) 
{ 
    int years = d.y; 
  
    if (d.m <= 2) 
        years--; 
  
    return years / 4 - years / 100 + years / 400; 
}

int getDifference(Date dt1, Date dt2) 
{ 
	const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
    long int n1 = dt1.y*365 + dt1.d; 
   
    for (int i=0; i<dt1.m - 1; i++) 
        n1 += monthDays[i]; 
   
    n1 += countLeapYears(dt1); 
    
    long int n2 = dt2.y*365 + dt2.d; 
    for (int i=0; i<dt2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2); 
   
    return (n2 - n1); 
}

Date getDate(Date sys_date)
{
	Date dt;
	
	cout << "\nEnter Date of Journey : ";
	
	while(1)
	{
	cout << "\n Year : ";
	cin >> dt.y;
	if (dt.y >= sys_date.y && dt.y <= 9999)
	break;
	else
	continue;
	}

	while(1)
	{
	cout << "\n Month : ";
	cin >> dt.m;
	if (dt.m >= 1 & dt.m <= 12)
	{
		if(dt.y == sys_date.y)
		{
		if(dt.m >= sys_date.m)
		break;
		else
		continue;
		}
		else
		break;
	}
	else
	continue;
	}
	
	while(1)
	{
	cout << "\n Day : ";
	cin >> dt.d;
	if (dt.d >= 1 & dt.d <= 31)
	{
		if(dt.m == sys_date.m)
		{
		if(dt.d >= sys_date.d)
		break;
		else
		continue;
		}
		else
		break;
	}
	else
	continue;
	}
	
	return dt;
}

int main()
{
	cout << "\t\tWelcome to Flight Price Estimator!\n";
	int ch, price;
	Date dt, sys_date;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	sys_date.y = 1900 + ltm -> tm_year;
	sys_date.m = 1 + ltm -> tm_mon;
	sys_date.d = ltm -> tm_mday;
	
	x:
	
	cout << "\nSelect Source : ";
	cout << "\n1. London (Heathrow)";
	cout << "\n2. New York (JFK)";
	cout << "\n3. Paris (Charles De Gaulle)";
	cout << "\n4. Tokyo (Narita)";
	
	cout << "\nEnter your Choice : ";
	cin >> ch;
	
	bool flag = true;
	for (int i = 1; i < 5; i++)
	{
		if (ch == i)
		{
			flag = false;
			break;
		}
		
	}
	
	if (flag)
	goto x;
		
	system("cls");
	
	switch(ch) 
	{
		case 1:
			cout << "\nSelect Destination";
			cout << "\n1. New York (JFK)";
			cout << "\n2. Paris (Charles De Gaulle)";
			cout << "\n3. Tokyo (Narita)";
			
			cout << "\nEnter your Choice : ";
			cin >> ch;
			
			switch (ch) //From London
			{
				case 1:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 747 @ 18:30 hrs";
					cout << "\n2. United Airlines 763 @ 12:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 20000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*50;
							cout << "\nEstimated Price for BA 747 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 15000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*45;
							cout << "\nEstimated Price for United 763 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 2:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 787 @ 19:30 hrs";
					cout << "\n2. Air France A320 @ 12:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 5000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*25;
							cout << "\nEstimated Price for BA 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 4000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*20;
							cout << "\nEstimated Price for Air France A320 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 3:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 787 @ 19:30 hrs";
					cout << "\n2. All Nippon Airways A350 @ 12:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 20000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*50;
							cout << "\nEstimated Price for BA 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 15000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*45;
							cout << "\nEstimated Price for ANA A350 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
				
				default:
					exit(0);
					
			}
			break;
			
		case 2:
			cout << "\nSelect Destination";
			cout << "\n1. London (Heathrow)";
			cout << "\n2. Paris (Charles De Gaulle)";
			cout << "\n3. Tokyo (Narita)";
			
			cout << "\nEnter your Choice : ";
			cin >> ch;
			
			switch (ch) //From New York
			{
				case 1:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 747 @ 18:30 hrs";
					cout << "\n2. United Airlines 763 @ 12:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 20000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*50;
							cout << "\nEstimated Price for BA 747 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 15000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*45;
							cout << "\nEstimated Price for United 763 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 2:
					cout << "\nSelect Flight";
					cout << "\n1. United 787 @ 11:30 hrs";
					cout << "\n2. Air France A330 @ 13:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 30000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*60;
							cout << "\nEstimated Price for United 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*55;
							cout << "\nEstimated Price for Air France A330 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 3:
					cout << "\nSelect Flight";
					cout << "\n1. United A380 @ 21:30 hrs";
					cout << "\n2. All Nippon Airways A350 @ 10:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*52;
							cout << "\nEstimated Price for United A380 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 18000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*48;
							cout << "\nEstimated Price for ANA A350 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
				
				default:
					exit(0);
					
			}
			break;
		
		case 3:
			cout << "\nSelect Destination";
			cout << "\n1. London (Heathrow)";
			cout << "\n2. New York (JFK)";
			cout << "\n3. Tokyo (Narita)";
			
			cout << "\nEnter your Choice : ";
			cin >> ch;
			
			switch (ch) //From Paris
			{
				case 1:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 737 @ 13:30 hrs";
					cout << "\n2. Air France A310 @ 08:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 2000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*10;
							cout << "\nEstimated Price for BA 737 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 2500;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*13;
							cout << "\nEstimated Price for Air France A310 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 2:
					cout << "\nSelect Flight";
					cout << "\n1. United 787 @ 00:30 hrs";
					cout << "\n2. Air France A330 @ 04:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 30000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*60;
							cout << "\nEstimated Price for United 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*55;
							cout << "\nEstimated Price for Air France A330 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 3:
					cout << "\nSelect Flight";
					cout << "\n1. Air France 767 @ 02:30 hrs";
					cout << "\n2. All Nippon Airways A350 @ 11:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*52;
							cout << "\nEstimated Price for Air France 767 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 18000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*48;
							cout << "\nEstimated Price for ANA A350 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
				
				default:
					exit(0);
					
			}
			break;
			
		case 4:
			cout << "\nSelect Destination";
			cout << "\n1. London (Heathrow)";
			cout << "\n2. New York (JFK)";
			cout << "\n3. Paris (Charles De Gaulle)";
			
			cout << "\nEnter your Choice : ";
			cin >> ch;
			
			switch (ch) //From Tokyo
			{
				case 1:
					cout << "\nSelect Flight";
					cout << "\n1. British Airways 787 @ 08:30 hrs";
					cout << "\n2. All Nippon Airways 747 @ 03:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 20000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*50;
							cout << "\nEstimated Price for BA 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*55;
							cout << "\nEstimated Price for ANA 747 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 2:
					cout << "\nSelect Flight";
					cout << "\n1. United 787 @ 01:30 hrs";
					cout << "\n2. All Nippon Airways A380 @ 06:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 30000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*60;
							cout << "\nEstimated Price for United 787 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*55;
							cout << "\nEstimated Price for ANA A380 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
					
				case 3:
					cout << "\nSelect Flight";
					cout << "\n1. Air France 767 @ 02:30 hrs";
					cout << "\n2. All Nippon Airways A350 @ 11:20 hrs";
					
					cout << "\nEnter your Choice : ";
					cin >> ch;
					
					if(ch == 1)
					{
						price = 25000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*52;
							cout << "\nEstimated Price for Air France 767 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";
					}
					
					else
					{
						price = 18000;
						dt = getDate(sys_date);
						ch = getDifference(sys_date,dt);
						
						if (ch <= 180)
						{
							cout << "\nBase Price is : " << price;
							cout << "\nDays until Journey : " << ch;
							price += ch*48;
							cout << "\nEstimated Price for ANA A350 is : " << price << "$";
						}
						else
							cout << "You're Booking 6 months prior to lift off!, Estimated Price is : " << price << "$";	
					}
					break;
				
				default:
					exit(0);
					
			}
			break;
			
		default:
			exit(0);	
	}
return 0;	
}

