#include <iostream>
#include <thread>

using namespace std;

int arr[] = {12, 45, 7, 89, 23, 56, 99, 34, 10, 67};

int max1;
int max2;

void findMaxPart1()
{
    max1 = arr[0];
    for(int i = 1; i < 5; i++)
    {
        if(arr[i] > max1)
            max1 = arr[i];
    }
}

void findMaxPart2()
{
    max2 = arr[5];
    for(int i = 6; i < 10; i++)
    {
        if(arr[i] > max2)
            max2 = arr[i];
    }
}

int main()
{
    thread t1(findMaxPart1);
    thread t2(findMaxPart2);

    t1.join();
    t2.join();

    int finalMax;

    if(max1 > max2)
        finalMax = max1;
    else
        finalMax = max2;

    cout << "Maximum element in array = " << finalMax << endl;

    return 0;
}