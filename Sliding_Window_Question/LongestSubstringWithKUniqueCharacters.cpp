// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 7
// Explanation: "cbebebe" is the longest 
// substring with K distinct characters.

#include "bits/stdc++.h"
using namespace std ;

int longestSubstring(string s ,int k)
{
    int i =0 ,j=0,ans =0 ;
    map<char , int > mp ;
    while(j<s.length())
    {
        mp[s[j]]++ ;
        if(mp.size()<k)
        {
            ans++ ; 
            j++ ;
        }else if(mp.size()==k)
        {
            ans=max(ans,j-i+1) ;
            j++ ;
        }else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]-- ;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]) ;
                }
                i++ ;
            }
            j++ ;
        }
    }
    return ans ;
}

int main()
{
    cout<<longestSubstring("aabacbebebe",3) ;
    return 0 ;
}