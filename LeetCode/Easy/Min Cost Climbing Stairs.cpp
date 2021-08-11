// URL : https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //dp vector to store the substructure problem cost
        vector<int> dp(cost.size()+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        //running a loop till 2 to the top most step and calculating the cost based on the condition
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(dp[i-1],dp[i-2])+ (i<cost.size()? cost[i] : 0);
        }
        
        return dp[cost.size()];
    }
};