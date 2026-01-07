#include <iostream>
using namespace std;

class math
{
private:
	int i;
public:
	math(int x)
	{
		i=x;
	}
	void set_i(int x)
	{
		i=x;
	}
	int get_i()
	{
		return i;
	}
};

void sqare_by_value (math m)
{
	m . set_i (m . get_i() * m . get_i());
	cout << "BY value the i is:"<< m.get_i()<<"\n";
}

void sqare_by_refarence (math *o)
{
	o->set_i(o->get_i() * o->get_i());
	cout<<"By referance the i is:"<<o->get_i()<<"\n";
}

int main()
{
	math a(10);
	sqare_by_value(a);
	cout<<"After call by value i:"<<a.get_i()<<"\n";
	sqare_by_refarence(&a);
	cout<<"After call by referance i:"<<a.get_i()<<"\n";
	return 0;
}