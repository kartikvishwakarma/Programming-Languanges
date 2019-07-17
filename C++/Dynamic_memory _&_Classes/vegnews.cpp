#include <iostream>
#include "strngbad.h"

using std::cout;

void callme1(StringBad &); // pass by reference
void callme2(StringBad ); // pass by value


int main(){
	using std::endl;
	{
		cout << "Starting an innner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		
		callme1(headline1); 
		cout << "headline1: " << headline1 << endl;
		
		callme2(headline2); // copy constructor called
		cout << "headline2: " << headline2 << endl;
		
		cout << "Initialize one object to another: \n";
		StringBad sailor = sports; // copy constructor
		cout << "sailor: " << sailor << endl;

		cout << "Assign one object to another: \n";
		StringBad knot;	// default constructor called
		knot = headline1;	// assignment operator called
		cout << "knot: " << knot << endl;
		
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";

	return 0;
}


void callme1(StringBad & rsb)
{
	cout << "String pass by reference:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "String pass by value:\n";
	cout << "	\"" << sb << "\"\n";
}