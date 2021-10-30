// Given a string S, find the length of the longest substring without repeating characters.


// Example 1:

// Input:
// S = "geeksforgeeks"
// Output:
// 7
// Explanation:
// Longest substring is
// "eksforg".

// Example 2:

// Input:
// S = "abdefgabef"
// Output:
// 6
// Explanation:
// Longest substring are
// "abdefg" , "bdefga" and "defgab".

#include "bits/stdc++.h"
using namespace std ;

int longestSubstringUnique(string s)
{
    int i=0,j=0,ans=0 ;
    map<char,int> mp ;
    while(j<s.length())
    {
        mp[s[j]]++ ;
        if(mp.size()==j-i+1)
        {
            ans = max(ans , j-i+1) ;
            j++ ;
        }else if(mp.size()<j-i+1)
        {
            while(mp.size()<j-i+1)
            {
                mp[s[i]]-- ;
                if(mp[s[i]]==0){
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
    cout<<longestSubstringUnique("geeksforgeeks") ;
    return 0 ;
}