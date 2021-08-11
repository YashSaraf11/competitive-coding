/*
    GFG : https://practice.geeksforgeeks.org/problems/maximize-toys0331/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(),arr.end());
        
        int count_toy=0;
        for(int i=0;i<arr.size();i++){
            if(K>=arr[i])
                count_toy++;
            K-=arr[i];
            if(K<0)
                 break;
            
        }
        return count_toy;
    }
};

int main(){
    int N, K;
    cout<<"Enter size of array and the amount K:";
    cin>>N>>K;

    vector<int> arr(N);
    cout<<"Enter array elements::\n";
    for(int i = 0;i < N;i++)
        cin>>arr[i];
        
    Solution ob;
    cout<<ob.toyCount(N, K, arr)<<endl;

return 0;
}