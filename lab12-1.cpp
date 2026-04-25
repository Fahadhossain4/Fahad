#include <iostream>
#include <thread>

using namespace std;

void Fun() {
    cout << "Hello from the thread!" << endl;
}

int main()
{
    thread t(Fun);
    t.join();
    cout << "Hello from the main thread!" << endl;
    return 0;
}