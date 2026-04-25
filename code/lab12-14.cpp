#include <iostream>
#include <thread>

using namespace std;

void checkPrime(int n)
{
    bool isPrime = true;

    if(n <= 1)
    {
        isPrime = false;
    }
    else
    {
        for(int i = 2; i <= n / 2; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    if(isPrime)
        cout << n << " is Prime" << endl;
    else
        cout << n << " is NOT Prime" << endl;
}

int main()
{
    int a = 17, b = 24, c = 29, d = 40;

    thread t1(checkPrime, a);
    thread t2(checkPrime, b);
    thread t3(checkPrime, c);
    thread t4(checkPrime, d);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}