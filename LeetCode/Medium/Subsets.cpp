// URL : https://leetcode.com/problems/subsets/submissions/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //to store the final result
        vector<vector<int>> result;
        
        //to store the intermediate array
        vector<int>currEle;
                
        backtracking(result,currEle,nums,0);
        return result;        
    }
    
    void backtracking(vector<vector<int>>& result,vector<int>currEle,vector<int>& nums,int index){
        //pushing the element in currEle for the instance into the result vector
        result.push_back(currEle);        
        
        //base condition to end the backtracking
        if(index>=nums.size())
            return;                
        
        //calling the function recursively for all possible subset
        for(int i=index;i<nums.size();i++){            
            currEle.push_back(nums[i]);                        
            backtracking(result,currEle,nums,i+1);
            currEle.pop_back();
        }
    }
};