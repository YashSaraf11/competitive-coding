/*
    GFG : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int> sorted(arr,arr+N);
      
      int count=1,maxCount=0;
      auto i=sorted.begin();
      for(auto j=next(sorted.begin(),1);j!=sorted.end();j++){
        if(*j-*i!=1){
            maxCount=max(maxCount,count);
            count=0;
        }
        count++;
        i=j;
      }
      
      return max(maxCount,count);
    }
};

int main()
{
    int  n,a[100001];
    cout<<"Enter size of array:";
    cin>>n;

    cout<<"Enter array elements::\n";
    for(int i=0;i<n;i++)
    cin>>a[i];

    Solution obj;
    cout<<obj.findLongestConseqSubseq(a, n)<<endl;     
    return 0;
}