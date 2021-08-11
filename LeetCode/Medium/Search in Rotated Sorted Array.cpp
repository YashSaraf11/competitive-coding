// URL : https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //marking the extremes for binary search
        int low=0,high=nums.size()-1;
                
        while(low<high){        
            int mid=(high-low)/2+low;                                    
            
            //checking if we need to search the second half
            if((nums[0]>nums[mid])^(nums[0]>target)^(target>nums[mid]))
                low=mid+1;
            else
                high=mid;
        }
        return low==high && nums[low]==target ? low : -1;   
    }
};