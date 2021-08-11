// URL : https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //base condition to see if the size is greater than 3 otherwise we return empty vector
        if(nums.size()<4)
            return {}; 
        
        //sorting the vector in the ascending order so that we can solve in better complexity
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-3;i++){            
            //condition to avoid duplicates since we would have already checked quadruplets for that number 
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            for(int j=i+1;j<nums.size()-2;j++){
                
                //condition to avoid duplicates since we would have already checked triplets for that number              
                if(j!=i+1 && nums[j]==nums[j-1])
                    continue;
                
                //setting boundary for finding the remaining two elements for quadruplets
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    //calculating the sum for the current instance
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];

                    //for sum is equal to target condition
                    if(sum==target){
                        //adding the triplet to the result vector
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});

                        //checking and moving to left and right for same number to avoid duplicates
                        while(left<right && nums[left]==nums[left+1])
                            left++;
                        while(left<right && nums[right]==nums[right-1])
                            right--;
                        left++,right--;                    
                    }
                    //if the sum was less than target(0) we need to move towards to the end of the array
                    else if(sum<target)
                        left++;
                    //if we are more than target(0) then we need to move towards to the start of the array
                    else
                        right--;
                }
            }
            
        }
        return res;
    }
};