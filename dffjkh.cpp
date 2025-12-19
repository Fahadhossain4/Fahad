#include <iostream>
using namespace std;

int main()
{
    long long i, j, count;
    cin >> i;

    long long arr1[i], arr2[i], arr3[i], arr4[i];

    for (j = 0; j < i; j++)
    {
        cin >> arr1[j] >> arr2[j] >> arr3[j] >> arr4[j];
    }

    for (j = 0; j < i; j++)
    {
        count = 0;

        if (arr1[j] < arr2[j]) 
        count++;
        if (arr1[j] < arr3[j]) 
        count++;
        if (arr1[j] < arr4[j]) 
        count++;

        cout << count << "\n";
    }

    return 0;
}
