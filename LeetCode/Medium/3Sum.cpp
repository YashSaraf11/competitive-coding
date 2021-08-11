// URL : https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //base condition to see if the size is greater than 3 otherwise we return empty vector
        if(nums.size()<3)
            return {}; 
        
        //sorting the vector in the ascending order so that we can solve in better complexity
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2 && nums[i]<1;i++){            
            //condition to avoid duplicates since we would have already checked triplets for that number 
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            //setting boundary for finding the remaining elements for triplets
            int left=i+1,right=nums.size()-1;
            while(left<right){
                //calculating the sum for the current instance
                int sum=nums[i]+nums[left]+nums[right];
                
                //for sum is equal to target condition
                if(sum==0){
                    //adding the triplet to the result vector
                    res.push_back({nums[i],nums[left],nums[right]});
                    
                    //checking and moving to left and right for same number to avoid duplicates
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left++,right--;                    
                }
                //if the sum was less than target(0) we need to move towards to the end of the array
                else if(sum<0)
                    left++;
                //if we are more than target(0) then we need to move towards to the start of the array
                else
                    right--;
            }
            
        }
        return res;
    }
};

/*
We sorted the array so we can find the suitable triplet in O(N*N) otherwise we would have taken a total of O(N^3).
Sorting decreased the complexity of finding the two remaining elements to O(N) from O(N*N) and thus decreased the time
complexity overall.

*/