// URL : https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        //base condition checking if the string are same
        if(word1==word2)
            return 0;

        //2D vector to store the number of operations required for the substrings of word1 and word2
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,INT_MAX-word1.length()-word2.length()));
        dp[0][0]=0;

        //setting up the base values required to make the string if either of them was null
        for(int i=1;i<=word2.length();i++)
            dp[0][i]=dp[0][i-1]+1;
        for(int i=1;i<=word1.length();i++)
            dp[i][0]=dp[i-1][0]+1;
        
        
        //using the word1 as row and word2 as column and traversing through them
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                //if the elements are same then we need to see what was the cost of making the substring withouts the current characters
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                //else we check the minimum cost in removing,deleting and adding respectively 
                else
                    dp[i][j]=min({dp[i][j],dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
            }
        }
        return dp[word1.length()][word2.length()];
    }
};