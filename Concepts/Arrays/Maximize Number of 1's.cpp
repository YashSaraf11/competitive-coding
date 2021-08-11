/*
    GFG : https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findZeroes(int arr[], int n, int m) {
        int l=0,r=0,count_zeroes=0,maxSize=0;
        //implementing a sliding window approach to find the solution in O(N) time
        while(l<=r && r<n){
            //checking if we are under the limit and if its a zero we increase the count of zero and move to the end of the array
            if(count_zeroes<=m){
                if(arr[r]==0)
                    count_zeroes++;
                r++;
            }
            //otherwise we move the start of the pointer towards the end and decrease the count of zero if we encounter one
            else if(count_zeroes>m){
                if(arr[l]==0)
                    count_zeroes--;
                l++;
            }

            //if we are under the limit then we can store the maximum length by comparing the existing length and r-l
            if(count_zeroes<=m)
                maxSize=max(maxSize,r-l);
        }
        return maxSize;
    }  
};

int main() {
    int n, i, m;
    cout<<"Enter size of array:";
    cin >> n;

    int arr[n];
    cout<<"Enter array elements::\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"Enter the limit of times we can flip '0':";
    cin >> m;

    Solution ob;
    cout<<ob.findZeroes(arr, n, m)<< "\n";

    return 0;
}