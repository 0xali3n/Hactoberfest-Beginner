#include<bits/stdc++.h>
using namespace std;
void towerofhanoi(int n,char frm, char to, char usng )
{
    if (n==1)
    {
        cout<<"Move 1 from "<<frm<<"  to "<<to<<"\n";
        return ;
    }
    towerofhanoi(n-1, frm, usng , to );
    cout<<"Move "<<n<<" from "<<frm<<" to  "<<to<<"\n";
    towerofhanoi(n-1, usng, to,frm);
}
int main()
{
    int n=6 ;
    towerofhanoi(n,'A','C','B') ;
}
 