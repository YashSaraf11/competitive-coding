/*
    LeetCode : https://leetcode.com/problems/climbing-stairs/submissions/
    GFG : https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
            
        return dp[n];
    }
};

int main()
{

    int m;
    cout<<"Enter nth step you want to calculate:";    
    cin>>m;

    Solution ob;
    cout<<ob.countWays(m)<<endl;

    return 0;
}
  // } Driver Code Ends