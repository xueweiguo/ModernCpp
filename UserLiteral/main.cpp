#include<iostream>

struct Distance
{
	explicit Distance(double val) :meters(val) {}
	long double meters{ 0 };
};

Distance operator""km(long double val)
{
	return Distance(val * 1000);
}

Distance operator""m(long double val)
{
	return Distance(val);
}

Distance operator""km(unsigned long long val)
{
	return Distance(val * 1000);
}
Distance operator""m(unsigned long long val)
{
	return Distance(val);
}

struct Time
{
	explicit Time(double val):seconds(val)
	{}
	friend Time operator""sec(unsigned long long val);
	friend Time operator""hour(long double val);

	long double seconds{ 0 };
};

Time operator""sec(long double val)
{
	return Time(val);
}

Time operator""hour(long double val)
{
	return Time(val * 3600);
}

Time operator""sec(unsigned long long val)
{
	return Time(val);
}

Time operator""hour(unsigned long long val)
{
	return Time(val * 3600);
}

struct Speed
{
	explicit Speed(double val) :speed(val)
	{}
	long double speed;
	friend Speed operator /(Distance d, Time t);
};

Speed operator /(Distance d, Time t)
{
	return Speed(d.meters / t.seconds);
}

int main()
{
	Distance d1{ 1000.0m };
	Time t1{ 2.0hour };
	Speed s1(d1 / t1);
	std::cout << "s1=" << s1.speed << "m/s" << std::endl;
	Speed s2{ 7.8km / 1sec };
	std::cout << "s2=" << s2.speed << "m/s" << std::endl;
	return 0;
}