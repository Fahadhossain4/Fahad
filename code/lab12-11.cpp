#include <iostream>
#include <thread>

using namespace std;

int arr[] = {1,2,3,4,5,6,7,8,9,10};
int sum1 = 0, sum2 = 0;

void sumFirstHalf()
{
    for(int i = 0; i < 5; i++)
    {
        sum1 += arr[i];
    }
}

void sumSecondHalf()
{
    for(int i = 5; i < 10; i++)
    {
        sum2 += arr[i];
    }
}

int main()
{
    thread t1(sumFirstHalf);
    thread t2(sumSecondHalf);

    t1.join();
    t2.join();

    int total = sum1 + sum2;

    cout << "Sum of array = " << total << endl;

    return 0;
}