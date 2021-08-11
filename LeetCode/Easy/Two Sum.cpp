// URL : https://leetcode.com/problems/two-sum/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map to store the index of the element
        map<int,int> indexStore;
        
        /*storing the index element encountered ,
            and if the element occured more than once then it stores the latest position*/
        for(int i=0;i<nums.size();i++)
            indexStore[nums[i]]=i;
        
        /*traversing the vector and checking if the target-nums[i] exist in the map and 
            that it is not the same element and if not then we return their indices*/
        for(int i=0;i<nums.size();i++){
            if(indexStore.count(target-nums[i]) && indexStore[target-nums[i]]!=i)
                return {i,indexStore[target-nums[i]]};
        }
        
        return {};
    }
};

/*
It works for duplicate elements since we only need two elements and we don't care if it is repeated more than twice since we will only be taking two at a time and we can always take one as the encountered at the last
*/