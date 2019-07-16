#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time &) const;
	Time operator*(const Time &) const;

	friend Time operator*(double m, const Time & t)
		{	return t*m; }
	void show() const;

	friend std::ostream & operator<<(std::ostream& os, const Time &t);
};

#endif

