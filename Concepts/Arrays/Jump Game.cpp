/*
    LeetCode: https://leetcode.com/problems/jump-game/
    GFG : https://practice.geeksforgeeks.org/problems/jump-game/1/#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int canReach(int A[], int N) {
        //marking the lastPos we have reached starting from end of the array
        int lastPosReached=N-1;
        for(int i=N-1;i>=0;i--){
            //if the ith index + A[ith] is greater than the last pos reached then we know we can reach the end of array from that index
            if(i+A[i]>=lastPosReached)
                lastPosReached=i;
        }
        //if we are able to reach start of the array that means we can reach the end from the start
        return lastPosReached==0;
    }
};

int main() {
    //taking input of number of elements
    int N;
    cout<<"Enter number of elements:";
    cin>>N;
    
    //taking input of the array elements
    int A[N];
    cout<<"Enter elements::\n";
    for(int i=0; i<N; i++)
        cin>>A[i];

    //calling the function to get the value
    Solution ob;

    return 0;
}