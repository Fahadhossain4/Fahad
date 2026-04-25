#include <iostream>
#include <thread>

using namespace std;

void factorial(int n)
{
    long long result = 1;

    for(int i = 1; i <= n; i++)
    {
        result *= i;
    }

    cout << "Factorial of " << n << " = " << result << endl;
}

int main()
{
    thread t1(factorial, 5);
    thread t2(factorial, 6);
    thread t3(factorial, 7);
    thread t4(factorial, 8);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}