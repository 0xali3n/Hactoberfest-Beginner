#include "bits/stdc++.h"
using namespace std ;

int countOcuurences(string txt , string pat)
{
    map<char , int > mp ;
    for (int i = 0; i < pat.length(); i++)
    {
        mp[pat[i]]++ ;
    }
    int i =0 ,j=0,ans =0 ;
    int n = txt.length(),k=pat.length() ;
    int count = mp.size() ;
    while(j<n)
    {
        if(mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]-- ;
            if(mp[txt[j]]==0)
            {
                count-- ;
            }
        }
        if(j-i+1<k)
        {
            j++ ;
        }else if(j-i+1==k)
        {
            if(count==0)
            {
                ans++ ;
            }
            if(mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++ ;
                if(mp[txt[i]]==1)
                {
                    count++ ;
                }
            }
            i++ ;
            j++ ;
        }
    }
    return ans ;
}

int main()
{
    cout<<countOcuurences("aabaabaa","aaba") ;
    return 0 ;
}