#include<bits/stdc++.h>
using namespace std;
 bool subset(vector<int>&nums,int n,int sum)
    {
        vector<vector<int>>dp(n+1,vector<int>((sum)+1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
       return dp[n][sum];
    }
    bool canPartition(vector<int>& nums,int n) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum&1) return false;
        return subset(nums,n,sum/2);
    }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums;
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        if( canPartition(nums,n))cout<<"can partition"<<endl;
        else cout<<"can't partition"<<endl;
    }
    return 0;
}