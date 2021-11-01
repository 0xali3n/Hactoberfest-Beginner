#include <iostream>
using namespace std;

class constructordemo
{
    public:
    constructordemo()
    {
        cout<<"I AM THE CONSTRUCTOR "<<endl;
        cout<<"no one calls me ! i get auto called when u declare class object! "<<endl;
    }

};

int main()
{
    constructordemo obj;


    return 0;
}


//This program is contributed by YASH RAJ MANI 
