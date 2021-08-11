/*
    GFG : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0;
        
        int index=1;
        while(i<n && j<m){
            int value;
            if(arr1[i]<=arr2[j])
                value=arr1[i++];
            else
                value=arr2[j++];
            
            if(index==k)
                return value;
            index++;
        }
        
        while(i<n){
            if(index==k)
                return arr1[i];
            
            i++,index++;
        }
        while(j<m){
            if(index==k)
                return arr2[j];
            
            j++,index++;
        }
        
        return -1;
    }
};

int main()
{
    int n,m,k;
    cout<<"Enter size of the arrays and the kth position:";
    cin>>n>>m>>k;

    int arr1[n],arr2[m];
    cout<<"Enter elements for array 1::\n";
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<"Enter elements for array 2::\n";
    for(int i=0;i<m;i++)
        cin>>arr2[i];
    
    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;

    return 0;
}