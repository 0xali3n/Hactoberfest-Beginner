#include <iostream>
using namespace std;

class destructordemo
{
public:
    destructordemo()
    {
        cout << "i am at begining I AM CONSTRUCTOR " << endl;
    }
    ~destructordemo()
    {
        cout << "no matter where i am after all ends, I AM destructor " << endl;
    }
    void disp()
    {
        cout << "helloo  i am member function " << endl;
    }
};

int main()
{
    destructordemo d1;
    d1.disp();

    return 0;
}
//This program is contributed by YASH RAJ MANI