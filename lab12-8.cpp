#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace chrono;

void singleThreaded()
{
    int count = 0;
    for(int i = 0; i < 100000000; i++)
    {
        count++;
    }
}

void multiThreaded()
{
    int count1 = 0, count2 = 0;
    thread t1([&count1] {
        for(int i = 0; i < 50000000; i++)
        {
            count1++;
        }
    });

    thread t2([&count2] {
        for(int i = 0; i < 50000000; i++)
        {
            count2++;
        }
    });

    t1.join();
    t2.join();
}

int main()
{
    auto start = high_resolution_clock::now();
    singleThreaded();
    auto end = high_resolution_clock::now();
    auto durationSingle = duration_cast<milliseconds>(end - start).count();
    cout << "Single threaded time: " << durationSingle << " ms" << endl;

    start = high_resolution_clock::now();
    multiThreaded();
    end = high_resolution_clock::now();
    auto durationMulti = duration_cast<milliseconds>(end - start).count();
    cout << "Multi threaded time: " << durationMulti << " ms" << endl;

    return 0;
}
