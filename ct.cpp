#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class timer
{
clock_t start;
public:
timer (); // constructor
~timer (); // destructor
};
timer ::timer ()
{
start = clock ();
}
timer ::~ timer ()
{
clock_t end;
end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	cout << "Elapsed time: " << fixed << setprecision(6) << elapsed << " seconds\n";
}
int main()
{
timer ob;
char c;
// delay ...
cout << "Press a key followed by ENTER: ";
cin >> c;
return 0;
}