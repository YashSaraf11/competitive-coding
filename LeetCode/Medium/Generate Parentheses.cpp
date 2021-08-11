// URL : https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //vector to store the result
        vector<string> result;    
        
        //calling the backtracking function 
        backtracking(result,"",0,n);
        return result;        
    }
    
    void backtracking(vector<string>& result,string currString,int open,int n){
        //base condition to return if the open braces less than 0 or greater than n
        if(open<0 || open>n)
            return ;
        
        /*if the length of string is equal to n*2, then we check if the 
            number of opening braces = number of closing braces,then we push */
        if(currString.length()/2==n){
            if(open==0)
                result.push_back(currString);
            return;
        }          
        
        //adding a '(' and ')' and calling the function again
        backtracking(result,currString+"(",open+1,n);
        backtracking(result,currString+")",open-1,n);
    }
};