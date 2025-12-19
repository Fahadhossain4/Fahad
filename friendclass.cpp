#include <iostream>
using namespace std;

class a
{
    private:
    int value;
    public:
    void set_v(int b);
    friend class b;
};

class b
{
    public:
    void show_v(a& p);
};

void a::set_v(int b)
{
    value=v;
}