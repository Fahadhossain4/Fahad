#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], arr1[n];
    
    for (int i=0;i<n;i++) 
    {
        cin >> arr[i];
        arr1[i]=-1;
    }

    for (int i=0;i<n;i++) 
    {
        int count = 1;
        for (int j=i+1;j<n;j++) 
        {
            if (arr[i]==arr[j]) 
            {
                count++;
                arr1[j]=0;
            }
        }
        if (arr1[i]!= 0)
        {
            arr1[i] = count;
        }
            
    }

    cout << "\nElement  Frequency\n";
    for (int i=0;i<n;i++) 
    {
        if (arr1[i]!= 0) {
            cout << arr[i] << "        " << arr1[i] << endl;
        }
    }

    return 0;
}