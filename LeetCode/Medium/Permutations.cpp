// URL : https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> result;    
    vector<vector<int>> permute(vector<int>& nums) {
        //to store the visited array to avoid adding elements multiple times
        vector<int> visited(nums.size(),0);
        
        //vector to store the current instance
        vector<int> currEle;
        
        backtrack(currEle,visited,nums);
        return result;
    }
    
    void backtrack(vector<int> currEle,vector<int> visited,vector<int> nums){\
        //base conditon to add to result and hault/end the backtracking 
        if(currEle.size()==nums.size()){
            result.push_back(currEle);
            return;
        }
                                                                             
        for(int i=0;i<nums.size();i++){
            //traversing the nums and if it isn't visited then we add and call it for remaining elements
            if(visited[i]==0){
                visited[i]=1;
                currEle.push_back(nums[i]);
                backtrack(currEle,visited,nums);
                
                //removing it and marking it as unvisited for other permutations
                currEle.pop_back();
                visited[i]=0;
            }
        }
    }
};