#include <algorithm>
#include <iostream>
#include <iterator>
class radix_test
{
    const int bit;
    public:
        radix_test(int offset) : bit(offset) {}
        bool operator()(int value) const
        {
            if (bit == 31)
                return value < 0;
            else
                return !(value & (1 << bit));
        }
};
 void lsd_radix_sort(int *first, int *last)
{
    for (int lsb = 0; lsb < 32; ++lsb)
    {
        std::stable_partition(first, last, radix_test(lsb));
    }
}
void msd_radix_sort(int *first, int *last, int msb = 31)
{
    if (first != last && msb >= 0)
    {
        int *mid = std::partition(first, last, radix_test(msb));
        msb--;
        msd_radix_sort(first, mid, msb);
        msd_radix_sort(mid, last, msb); 
    }
}
int main()
{
    int data[] = {5,4,10,100,50,30,25,5};
    std::cout << "Before Sorting:" << std::endl;
    std::copy(data, data + 8, std::ostream_iterator<int>(std::cout, " "));
    lsd_radix_sort(data, data + 8);
    std::cout << "\nAfter Sorting:" << std::endl;
    std::copy(data, data + 8, std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
