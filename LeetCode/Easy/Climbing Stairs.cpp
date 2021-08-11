
// URL : https://leetcode.com/problems/climbing-stairs/submissions/

class Solution {
public:
    //function to calculate the number of ways to reach the top
    int climbStairs(int n) {
        //1D vector to store the number of ways for the intermediate step
        vector<int> dp(n+1);
        dp[0]=dp[1]=1;
        
        //traversing the vector till n and adding the number of ways we can reach i-1 and i-2
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
