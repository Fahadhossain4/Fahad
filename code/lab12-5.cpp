#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int count=0;
mutex m;
void fun1()
{
    for(int i = 0; i < 3000000; i++)
    {
        lock_guard<mutex> lock(m);
        count++;
    }
}

int main()
{
    thread t1(fun1);
    thread t2(fun1);
    t1.join();
    t2.join();
    cout << "The final value of count is: " << count << endl;
    return 0;
}


