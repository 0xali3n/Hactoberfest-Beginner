#include<iostream>
#include<sstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


vector<int>parseInts(string str)
{
    vector<int>res;
    // to store sigle string
    int i;
    stringstream iss(str);
    // >> add to string stream
    //  << read to stringstream
    while(iss >> i)
    {
        res.push_back(i);
        if(iss.peek()==',')
        {
            iss.ignore();
        }
    }
    return res;
}
int main(){
    // string to vector integer sparseInts
    string str;
    cin>>str;
    vector<int>mynum=parseInts(str);
    for(int i=0;i<mynum.size();i++)
    {
        cout<<mynum[i]<<" ";
    }
}
