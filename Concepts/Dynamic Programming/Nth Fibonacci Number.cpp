/*
    Leetcode : https://leetcode.com/problems/fibonacci-number/
    GFG : https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n+1,0);
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return dp[n];
    }
};


int main() {
    long long int n;
    cout<<"Enter n to calculate nth fibonacci number:";
    cin >> n;
    
    Solution ob;
    cout << ob.nthFibonacci(n) << endl;
    return 0;
}