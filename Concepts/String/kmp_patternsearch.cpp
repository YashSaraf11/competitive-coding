/*
    LeetCode : https://leetcode.com/problems/shortest-palindrome/
    GFG : https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#

*/

#include<bits/stdc++.h>
using namespace std;

void computePrefixArray(string p, vector<int> &lps){
    //the value of the prefix array at 0th index will always be 0
    lps[0]=0;

    //length of the longest prefix suffix
    int len=0;

    //traversing the pattern from 1 
    int i=1;
    while(i<p.length()){
        //if the characters match then we know that we have to come to the len+1 in case of mismatch
        if(p[i]==p[len]){
            lps[i]=len+1;
            i++,len++;
        }

        else{
            //if mismatched we go back to the previous suffix
            if(len!=0)
                len=lps[len-1];
            //if the len of previous suffix becomes 0 we know that we haven't encountered any matched prefix 
            else
                lps[i]=0;
                i++;
        }
    }
}

vector<int> KMP(string s,string p){
    //vector to store the position where the string and the pattern matches
    vector<int> pos;
    
    //vector to store the prefix value
    vector<int> lps(p.length());

    //function to precompute the prefix array matching 
    computePrefixArray(p,lps);

    //traversing the string to match with the pattern
    int i=0,j=0;
    while(i<s.length()){
        //if the element at the string and the pattern matches then we increase the value of both i and j
        if(s[i]==p[j])
            i++,j++;
        
        //if we reach the end of the pattern then we have found the pattern and then we change the value of j to the value of the last element in the prefix array
        if(j==p.length()){
            pos.push_back(i-j);
            j=lps[j-1];
            continue;
        }

        //if the character at the string and the pattern doesn't match then we check if there's any prefix if yes we go to that otherwise we move forward in the string
        if(s[i]!=p[j]){
            if(j!=0)
                j=lps[j-1];
            else
                ++i;
        }

    }
    return pos;
}

int main(){
    //taking input for the string and pattern to match
    string s,p;
    cout<<"Enter the string:";
    cin>>s;
    cout<<"Enter the pattern:";
    cin>>p;

    vector<int> pos = KMP(s,p);
    if(pos.size()>0){
        cout<<"The position that the pattern matched are: ";
        for(int i:pos)
            cout<<i<<" ";
    }
    else{
        cout<<"The pattern didn't matcht the string";
    }
    return 0;
}