// URL : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {        
        /*
            count_subArray stores the final answer and count of all the sub-array that satisfy the requirment
            
            current_subArray contains the number of sub-sub-array the sub-array from i->j provides that 
                satisfy the requiment
                
            i marks the start of the sub-array we are currently looking at and j marks the end of it        
        */
        int count_subArray=0,current_subArray=0,i=0;
        
        for(int j=0;j<nums.size();j++){
            /*if we encounter a number greater than Right then we need to find a new sub-array so we shift the start to
                j+1, so i=j+1 and since the current-subarray provides 0 subarray that satisfy we change it to 0 
            */
            if(A[j]<right){
                i=j+1;
                current_subArray=0;
            }
            /*
                if we encounter an element greater than left then we know it will give us total sub-arrays of its length 
                that satsifies its requirment
            */
            else if(A[j]>=left){
                current_subArray=j-i+1;
            }            
            /*
                we add the total subarray we got from the current length of subarray to the total result,
                and if we encounter an element less than left then we know it wouldn't add any extra sub-array to
                the total and hence the current_subArray value remains the same
            */
            count_subArray += current_subArray;
        }
        return count_subArray;
    }
};