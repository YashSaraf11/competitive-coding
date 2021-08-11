/*
    LeetCode : https://leetcode.com/problems/partition-equal-subset-sum/
    GFG : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums,int sum) {        
        //making a 2D dp vector to store the intermediate result
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        dp[0][0]=true;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][sum];
    }
};

int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter n elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int sum;
    cout<<"Enter target sum:";
    cin>>sum;

    Solution ob;
    cout<<"THe subset can be divided into a sum with value of target:"<<ob.canPartition(arr,sum);
    return 0;
}