/*
    LeetCode : https://leetcode.com/problems/longest-increasing-subsequence/
    GFG : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //function to calculate the longest increasing subsequence in the given vector/array
    int lengthOfLIS(vector<int>& nums) {
        //1D vector/array to store the maxiumum length encountered at that index
        vector<int> dp(nums.size(),1);

        //traversing the nums array from the end to start
        for(int i=nums.size()-1;i>=0;i--){
            //traversing from i+1th index to the end and checking if the element at j is greater than we know there's an increasing subsequence and store that value+1 for dp[i]
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }

        //we traverse the dp vector and find the maximum length of increasing subsequence 
        int max_ele = *max_element(dp.begin(),dp.end());
        return max_ele;
    }
};

int main(){
    int n;
    cout<<"Enter number of elements for the array:";
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Solution ob;
    cout<<"The length of largest common subsequence is : "<< ob.lengthOfLIS(arr);
    return 0;
}