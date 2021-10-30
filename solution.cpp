//author_name=Jayant Sharma.
#include <bits/stdc++.h>
 
using namespace std;
/*In this problem, Casimir's goal is to erase all letters from the string.
he can do reduce the length of string upto only 2 letters in one step from a string 
either by removing 'A'&'B' or  by removing 'B' &'C'.
So, number of B's are equal to sum of A's and B's in order to erase all alphabets from string.*/

int main()
{
    int t;
    cin>>t;
    while(t--) //running loop untill test cases vanishes.
    {
        int ans=0; // initialised ans to 0.
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++) //running loop to traverse all alphabets of string.
        {
            if(s[i]=='B')
                ans++; //calculating number of B's in string.
        }
        if(2*ans==s.length()) // checking number of B's are equal to sum of A"s and C's or equal to half of string length.
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;