#include <iostream>
#include <string>
template<typename T>
class Test
{
private:
	T data;
public:
	Test();
	Test(T d);
	void show() const;
};

template<typename T>
Test<T>::Test() 
{
	data = 0;
}


template<typename T>
Test<T>::Test(T d) 
{
	data = d;
}

template<typename T>
void Test<T>::show() const
{
	std::cout << data << std::endl;	
}

int main(){
	Test<int> test(34);
	Test<double> dtest(3.769);
	Test<std::string> stest("Hello world!");
	test.show();
	dtest.show();
	stest.show();
	return 0;
}
