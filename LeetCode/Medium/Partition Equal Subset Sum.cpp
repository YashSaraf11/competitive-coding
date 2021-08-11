// URL : https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //checking if the sum of the array is even, otherwise we can't divide it into two subset
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)
            return false;
        sum/=2;
        
        //making a 2D dp vector to store the intermediate result
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        dp[0][0]=true;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j] || dp[i][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum];
    }
};