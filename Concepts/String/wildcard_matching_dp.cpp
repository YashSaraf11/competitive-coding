/*
    LeetCode : https://leetcode.com/problems/wildcard-matching/
    GFG : https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

*/

#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s,string p){
    //2D vector to store the intermediate result
    vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1));

    //setting up the basic values of null strings 
    dp[0][0]=1;
    for(int i=1;i<=p.length();i++)
        dp[0][i] = (p[i-1]=='*')? dp[0][i-1] : false;
    for(int i=1;i<=s.length();i++)
        dp[i][0]=false;

    //traversing the string and the pattern for the intermediate result 
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=p.length();j++){
            //if the characters match or if the pattern has '?' then we need to check the result of the values removing those characters that is stored at dp[i-1][j-1]
            if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            //if the pattern character is '*' then we need to check the intermediate results of without the characters     
            else if(p[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            //otherwise we know we can't make the text from the pattern for the intermediate result
            else   
                dp[i][j]=false;
        }
    }
    //returning the value
    return dp[s.length()][p.length()];
}

int main(){
    //taking input for the text and pattern to match
    string s,p;
    cout<<"Enter the string:";
    cin>>s;
    cout<<"Enter the pattern:";
    cin>>p;

    //calculating the result of the wildcard matching
    bool result = isMatch(s,p);
    cout<<result<<"\n";
    return 0;
}