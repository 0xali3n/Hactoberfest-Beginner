#include <iostream>
using namespace std;
int main(){
	int arr[3][2] = {
{1234, 56},
{1212, 33},
{1434, 80},
} ;
   {
    cout <<arr[0]<<endl;
    cout <<*arr[0]<<endl;
   }
{cout<<"56"<<endl;}
   { //locating 56
    cout<<"56=="<<arr[0][1]<<"    arr[0][1]"<<endl;
    cout<<"56=="<< *(arr[0]+1)<<"    *(arr[0]+1)"<<endl;  
    cout<<"56=="<<*(*arr+1)<<"    *(*arr+1)"<<endl;
   } 
{cout<<"33"<<endl;}
   { //locating 33
    cout<<"33=="<<arr[1][1]<<"    arr[1][1]"<<endl;
    cout<<"33=="<< *(arr[1]+1)<<"    *(arr[1]+1)"<<endl; 
    cout<<"33=="<<*(*arr+3)<<endl;	
   }
{cout <<"80"<<endl;}
   { // locating 80
    cout<<"80=="<<arr[2][1]<<endl;
    cout<<"80=="<<*(arr[2]+1)<<endl;
    cout<<"80=="<<*(*arr+5)<<endl;
   }
 {cout<<"1234"<<endl;}
   {//locating 1234
   cout<<"1234=="<<arr[0][0]<<endl;
   cout<<"1234=="<<*arr[0]<<endl;
   cout<<"1234=="<<*(*arr+0)<<endl;
   }
 {cout<<"1212"<<endl;}
   {//locating 1212
   cout<<"1212=="<<arr[1][0]<<endl;
   cout<<"1212=="<<*arr[1]<<endl;
   cout<<"1212=="<<*(*arr+2)<<endl;
   }
 {cout<<"1434"<<endl;}
   {//locating 1434
   cout<<"1434=="<<arr[2][0]<<endl;
   cout<<"1434=="<<*arr[2]<<endl;
  cout<<"1434=="<<*(*arr+4)<<endl;
   }
 /*  int arr[4]={1,2,3,4};
   cout<<<<endl;*/
return 0;	
   } 
