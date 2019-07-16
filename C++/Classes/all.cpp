#include <iostream>

template<typename T>
class Time
{
private:
	T hours;
	T minutes;
public:
	Time();
	Time(T h, T m = 0);
	void AddMin(T m);
	void AddHr(T h);
	void Reset(T h = 0, T m = 0);
	Time operator+(const Time &) const;
	Time operator*(const Time &) const;

	/*friend Time operator*(double m, const Time & t)
		{	return t*m; }*/
	void show() const;

	//friend std::ostream & operator<<(std::ostream& os, const Time &t);
};

template<typename T>
Time<T>::Time()
{
	hours = minutes = 0;
}

template<typename T>
Time<T>::Time(T h, T m)
{
	hours = h;
	minutes = m;
}

template<typename T>
void Time<T>::AddMin(T m)
{
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

template<typename T>
void Time<T>::AddHr(T h)
{
	hours += h;
}

template<typename T>
void Time<T>::Reset(T h, T m)
{
	hours = h;
	minutes = m;
}

template<typename T>
Time<T> Time<T>::operator+(const Time &t) const
{
	Time sum;
	sum.minutes = (minutes + t.minutes);
	sum.hours = hours + t.hours + sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

template<typename T>
void Time<T>::show() const
{
	std::cout << hours << " hours, " << minutes << " minutes\n";
}

int main()
{
	using std::cout;
	using std::endl;

	Time<int> planning;
	Time<int> coding(2,40);
	Time<int> fixing(5,55);
	Time<int> total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	total = coding + fixing;

	cout << "coding + fixing = ";
	total.show();
	cout << endl;
}