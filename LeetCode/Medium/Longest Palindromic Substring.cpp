// URL : https://leetcode.com/problems/longest-palindromic-substring/solution/

class Solution {
public:
    string longestPalindrome(string s) {
        //base condition to return 
        if(s.length()<2)
            return s;
        
        //making a dp vector to store the palindromic state of the substrings 
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        for(int i=0;i<s.length();i++)
                dp[i][i]=true;
        
        //storing the maximum length of and the start to get the substring
        int longestPalindromeLength=1,palindromeStart=0;
        
        //traversing the array from size to 0
        for(int start=s.length()-1;start>=0;start--){    
            //traversing from start to size to check if its palindrome
            for(int end=start+1;end<s.length();end++){
                //if the end characters are same then we check the state of the remaining substring
                if(s[start]==s[end]){
                    if(start+1==end || dp[start+1][end-1]){
                        dp[start][end]=true;
                        //updating the length and start of new palindromic substring
                        if(longestPalindromeLength<end-start+1){
                            palindromeStart=start;
                            longestPalindromeLength=end-start+1;
                        }
                    }
                }
            }
        }
        //returning the palindromic substring with maximum length 
        return s.substr(palindromeStart,longestPalindromeLength);
    }
};