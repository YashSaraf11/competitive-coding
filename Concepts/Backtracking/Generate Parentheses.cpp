/*
    Leetcode : https://leetcode.com/problems/generate-parentheses/
    GFG : https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1#
*/

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        //vector to store the possible parenthesis combination
        vector<string> result;
        
        //calling the backtrack function to generate all the combinations
        backtrack(result,"",0,n);
        return result;
    }
    

    void backtrack(vector<string>& result,string currString,int open,int n){
        /* base condition to end the backtracking
            checking if the opening braces is more than the limit n or if the closing braces are more than opening braces
            then we end the recursion
                */
        if(open<0 || open>n)
            return ;
            
        /*
            we check if the length of the currentString we have for current iteration is equal to the number of pairs of braces required
                we add it to the result if it satisfies the condition
            */
        if(currString.length()==n*2){
            if(open==0)
                result.push_back(currString);
            return ;
        }
        
        //otherwise we continue the backtracking recursion by adding an '(' and one for ')' 
        backtrack(result,currString+"(",open+1,n);
        backtrack(result,currString+")",open-1,n);
    }
};

int main() 
{ 
    int n;
    cout<<"Enter number of paranthesis pair:";
    cin>>n;

    Solution ob;
    vector<string> result = ob.AllParenthesis(n); 

    //sorting to keep the result in a easy to decipher manner
    sort(result.begin(),result.end());
    for (int i = 0; i < result.size(); ++i)
        //printing the returned result
        cout<<result[i]<<"\n";

	return 0; 
} 