// URL : https://leetcode.com/problems/jump-game/submissions/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //marking the lastPos we have reached starting from end of the array
        int lastPosReached=nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            //if the ith index + A[ith] is greater than the last pos reached then we know we can reach the end of array from that index
            if(i+nums[i]>=lastPosReached)
                lastPosReached=i;
        }
        //if we are able to reach start of the array that means we can reach the end from the start
        return lastPosReached==0;
    }
};

/*
We can start from the start of the array as well but we need to change the loop boudnaries and the if condtion
    if(i+nums[i]>=lastPosReached && i<=lastPosReached)
        lastPosReached = i+nums[i]
because we can't update the value if we can't reach that index and the max index we can reach is i+nums[i] and we need to see if we reach
the end of array instead of start
*/