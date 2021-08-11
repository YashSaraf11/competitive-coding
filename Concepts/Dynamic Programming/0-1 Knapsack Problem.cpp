/*
    LeetCode : https://leetcode.com/problems/partition-equal-subset-sum/
    GFG : https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //sorting the vector to avoid running to the end of the vector
        vector<pair<int,int>> wt_val;
        for(int i=0;i<n;i++){
              wt_val.push_back({wt[i],val[i]});
        }
        sort(wt_val.begin(),wt_val.end());
        
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        //setting up the conditions to modify the dp vector to give max profit
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(j<wt_val[i-1].first){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],wt_val[i-1].second+dp[i-1][j-wt_val[i-1].first]);
                }
            }
        }
        return dp[n][W];        
    }
};

int main()
 {
    //reading number of elements and weight
    int n, w;
    cin>>n>>w;
    
    int *val= new int[n];
    int *wt = new int[n];
    
    //inserting the values and weights
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];

    Solution ob;
    cout<<ob.knapSack(w, wt, val, n)<<endl;  

	return 0;
} 