#include<iostream>
using namespace std;

class car
{
private:
	double price;
public:
	void set_price(double p);
	friend void get_price(car& c);
};

void car::set_price(double p)
{
	price=p;
}

void get_price(car& c)
{
	cout<<"Price is:"<<c.price;
}

int main()
{
	car c;
	c.set_price(123456789);
	get_price(c);
	return 0;
}