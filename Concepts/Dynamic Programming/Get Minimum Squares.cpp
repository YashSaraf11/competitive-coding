/*
    Leetcode : https://leetcode.com/problems/perfect-squares/
    GFG : https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1#
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int MinSquares(int n)
	{
        //checking if the number is a perfect square then we can just return 1
	    if(floor(sqrt(n))==ceil(sqrt(n)))
	            return 1;
	        
        //if it's not a perfect square , then we build the array upto n
	    vector<int> dp(n+1);
	    dp[0]=0;
	    dp[1]=1;
	    
        //building the array to n to avoid recomputation
	    for(int i=2;i<=n;i++){
            //checking if the number is a perfect square then we can just store 1
	        if(floor(sqrt(i))==ceil(sqrt(i)))
	            dp[i]=1;
	       else{
               //the max value can be i times 1 for a particular value i
	           dp[i]=i;
               
               //running the loop till the sqrt and storing the minimum value generated till there
	           for(int j=1;j<=ceil(sqrt(i));j++){
	               int v=j*j;
	               if(v>i)
	                  break;
	               dp[i]=min(dp[i],1+dp[i-v]);
	           }
	       }
	            
	    }
	    return dp[n];
	}
};

int main(){
    int n;
    cout<<"Enter the number:";
    cin >> n;

    Solution ob;
    cout<<ob.MinSquares(n)<<"\n";
    
	return 0;
}