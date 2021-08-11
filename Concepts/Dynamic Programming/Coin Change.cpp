/*
     LeetCode : https://leetcode.com/problems/coin-change-2/
     GFG :  https://practice.geeksforgeeks.org/problems/coin-change2448/1#
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0]=1;
        
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i])
                    dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

int main()
{
    int n,m;
    cout<<"Enter the number of coins and the target amount:";
    cin>>n>>m;
    
    vector<int> coins(n);
    cout<<"Enter the n elements:";
    for(int i=0;i<n;i++)
        cin>>coins[i];

    Solution ob;
    cout<<ob.change(m,coins)<<endl;   
    return 0;
}