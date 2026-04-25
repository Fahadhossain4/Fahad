#include <iostream>
using namespace std;

class area
{
    private:
    int radious;
    public:
    void set_radious(int r)
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
    area *a = new area;
    if(!a)
    {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
    a->set_radious(10);
    cout << "Area:" << a->get_area() << endl;
    delete a;
    return 0;
}