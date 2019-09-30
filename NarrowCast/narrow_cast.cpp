#include<iostream>
#include<gsl>

using namespace std;
using namespace gsl;

class BaseClass
{
public:
	void bfun(){
		cout << "BaseClass::bfun()" << endl;
	}
	virtual void vfun() {
		cout << "BaseClass::vfun()" << endl;
	}
};

class SubClass : public BaseClass
{
public:
	virtual void vfun() {
		cout << "SubClass::vfun()" << endl;
	}
};

/*
int mul(int a, int b) {
	return a * b;
}
*/

template<typename T1, typename T2>
auto mul(T1 a, T2 b) ->decltype(a*b)
{ 
	return a * b;
}

int main()
{
	BaseClass* bc = new SubClass();
	bc->bfun();
	bc->vfun();

	cout << mul(3, 5) << endl;
	cout << mul(2.7, 5.6) << endl;
	cout << mul(2.7, 5) << endl;
	cout << mul(narrow_cast<int>(3.4), narrow_cast<int>(2.8)) << endl;

	cout << mul(narrow<int>(3), narrow<int>(8)) << endl;
	cout << mul(narrow<int>(3.4), narrow<int>(2.8)) << endl;

	return 0;
}