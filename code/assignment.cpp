// This program contains an error .
#include <iostream>
using namespace std;
class base
{
int x;
public :
void setx (int n) { x = n; }
int showx () { return x; }
};
// Inherit base as private .
class derived : private base
{
int y;
public :
void sety (int n) { y = n; }
derive() setx (10) ; // access member of base class - OK
void showy () { cout << y+showx() << '\n'; }
};
int main ()
{
derived ob;
// ERROR - now private to derived class
ob. sety (20) ; // access member of derived class - OK
// ERROR - now private to derived class
ob. showy (); // access member of derived class - OK
return 0;
}