// URL : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/submissions/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(),candies.end());        
        
        vector<bool> res;
        for(int i:candies){
            (i+extraCandies>=maxCandy) ? res.push_back(true) : res.push_back(false);
        }
        
        return res;
    }
};