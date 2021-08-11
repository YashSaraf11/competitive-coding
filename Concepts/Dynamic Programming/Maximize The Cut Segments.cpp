/*
    GFG : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int x_value=0,y_value=0,z_value=0;
            if(i>=x && (dp[i-x]!=0 || i%x==0))
                x_value=1+dp[i-x];
            if(i>=y && (dp[i-y]!=0 || i%y==0))
                y_value=1+dp[i-y];
            if(i>=z && (dp[i-z]!=0 || i%z==0))
                z_value=1+dp[i-z];
                
            dp[i]=max({dp[i],x_value,y_value,z_value});
        }
        return dp[n];
    }
};

int main() {    
    int n;
    cout<<"Enter the length of rod:"<<n;
    cin>>n;

    int x,y,z;
    cout<<"Enter the x,y and z segment value:";
    cin>>x>>y>>z;

    Solution ob;
    cout<<"The maximum number of segments we can obtain: "<<ob.maximizeTheCuts(n,x,y,z);
    
    return 0;
}