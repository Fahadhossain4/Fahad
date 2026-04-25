#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int count = 0;
bool ready = false;

mutex m;
condition_variable cv;

void fun1()
{
    unique_lock<mutex> lock(m);

    cv.wait(lock, [] { return ready; });

    for(int i = 0; i < 1000000; i++)
    {
        count++;
    }
}

int main()
{
    thread t1(fun1);

    {
        lock_guard<mutex> lock(m);
        ready = true;
    }

    cv.notify_one();

    t1.join();

    cout << "The final value of count is: " << count << endl;
    return 0;
}