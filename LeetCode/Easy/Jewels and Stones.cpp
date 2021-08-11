// URL : https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> dp(256,0);
        for(char ch:jewels)
            dp[ch]++;
        
        int jewelsCount=0;
        for(char ch:stones){
            if(dp[ch])
                jewelsCount++;
        }
        return jewelsCount;
    }
};