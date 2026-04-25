#include <iostream>
#include <thread>

using namespace std;

void fun1()
{
    for(int i = 0; i < 15; i++)
    {
        cout << "Thread 1: " << i << endl;
    }
}

int main()
{
    cout << "Main thread is starting." << endl;
    thread t1(fun1);
    cout << "Thread 1 has been started." << endl;
    t1.join();
    cout << "Thread 1 has finished execution." << endl;
    thread t2(fun1);
    cout << "Thread 2 has been started." << endl;
    t2.detach();
    cout << "Thread 2 has finished execution." << endl;
    cout << "Threads have finished execution." << endl;

    return 0;
}