#include <iostream>
using namespace std;

class area
{
    private:
    int radious;
    public:
    area(int r)
    {
        radious = r;
    }
    double get_area()
    {
        return 3.14 * radious * radious;
    }
};

int main()
{
    area *a;
    a = new area(10);
    if(!a)
    {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
    cout << "Area:" << a->get_area() << endl;
    delete a;
    return 0;
}