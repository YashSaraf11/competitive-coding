// URL : https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    //function to calculate the longest common subsequence b/w the two given string
    int longestCommonSubsequence(string text1, string text2) {
        //2D vector/array to keep track of the maximum length encountered for the intermediate string
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));        

        //using the text1 as row and text2 as column and traversing through them
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++)
                //if we find that the characters are same then we go diagonally left and see the value of max length then and add one to it cause we found a character match
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                // if the characters don't match then we check if either of the value on the left or the top is maximum and store that since that will be the maximum value for that substrings
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[text1.length()][text2.length()];
    }
};
