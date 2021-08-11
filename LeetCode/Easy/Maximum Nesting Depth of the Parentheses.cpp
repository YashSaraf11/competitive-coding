// URL : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        //to track the number of openbraces at the current position
        int openBraces=0;
        
        //calculating max depth of open parenthesis
        int depth=0;
        for(char ch:s){
            if(ch=='(')        
                ++openBraces;
            else if(ch== ')'){
                depth=max(depth,openBraces);
                openBraces--;
            }                
        }
        return depth;
    }
};