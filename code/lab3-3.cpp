#include <iostream>
using namespace std;

class microphone
{
    public:
    microphone()
    {
        cout<<"Microphone is working."<<"\n";
    }
};

class camera
{
    public:
    camera()
    {
        cout<<"Camera is working."<<"\n";
    }
};

class speaker
{
    public:
    speaker()
    {
        cout<<"Speaker is working."<<"\n";
    }
};

class phone : public microphone, public camera, public speaker
{
    public:
    phone()
    {
        cout<<"Phone is fully working."<<"\n";
    }
};

int main ()
{
    phone p;
    return 0;
}