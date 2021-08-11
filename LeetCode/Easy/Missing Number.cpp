// URL : https://leetcode.com/problems/missing-number/solution/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*since the array contains all the numbers from 0->n , both ends included 
            we can find the sum of n natural numbers and subtract it from elements inside the array and the remaining value will be the 
                number missing */
        int sum=(nums.size()*(nums.size()+1))/2;
        for(int i:nums)
            sum-=i;
        
        return sum;
        
    }
};