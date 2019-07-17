#include <cstring>
#include "String.h"

using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
} 


String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str,s);
	num_strings++;
	cout << num_strings << " : \"" << str << "\" object created\n"; 
}

String::String(){
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
	cout << "\" default object created\n"; 
}

String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	cout << num_strings << " :\" " << str << " \"object created because of copy constructor.\n";
}

String::~String(){
	cout << "\"" << str << "\" object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete [] str;
}



String & String::operator=(const String & st)
{
	std::cout << "assignment operator called. \n";
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len+1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char *s)
{
	std::cout << "assignment operator called. \n";
	delete [] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;
}

//read-write access
char & String::operator[](int i) 
{
	return str[i];
}

// read only access
const char & String::operator[](int i) const
{
	return str[i];
}


bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}


std::ostream& operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	if(is)
		st = temp; // call to st.operator=(const char *)

	while(is && is.get() != '\n')
		continue;

	return is;
}
