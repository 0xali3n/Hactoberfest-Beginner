#include <iostream>
#include <math.h>
using namespace std;
int main()
{ int lim, sum, num,n,digit;
  cout<<"Enter the limit of the numbers";
  cin>>lim;
  n=1;
  do {
  sum = 0;
  num = n;
  do{
  digit = num%10;
  sum = sum+pow(digit,3);
  num = num/10;
} while(num>0);
if(sum == n)
cout<<n<<"\t";
n++;
} while(n<lim);
return 0;

}