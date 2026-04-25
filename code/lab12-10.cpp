#include <iostream>
#include <thread>

using namespace std;

void printOdd()
{
    for(int i = 1; i <= 10; i += 2)
    {
        cout << i << " ";
    }
}

void printEven()
{
    for(int i = 2; i <= 10; i += 2)
    {
        cout << i << " ";
    }
}

int main()
{
    thread t1(printOdd);
    thread t2(printEven);

    t1.join();
    t2.join();

    return 0;
}