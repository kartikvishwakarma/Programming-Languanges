// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	//setting things up

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);	// line queue holds upto qs people

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;	// # of cycles

	cout << "Enter the average number of customer per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;	// average time betwen arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	// running simulation

	for(int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if(newcustomer(min_per_cust))	// have newcomer
		{
			if(line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if(wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}

		if(wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	// reporting resulus

	if(customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " average wait time: "
			 << (double) line_wait / served << " minutes\n\n";
	}
	else
		cout << "No customers!\n\n";

	cout << "Done!!!\n\n";

	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}