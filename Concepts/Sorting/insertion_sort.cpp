#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> array){

}
int main(){
    //taking input of number of elements to sort
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    //taking input of the elements to sort
    vector<int> array(n);
    cout<<"Enter "<<n<<" elements:\n";       
    for(int i=0;i<n;i++)        
        cin>>array[i];

    //the sorted array returned is stored into the vector(sortedArray)
    vector<int> sortedArray = merge_sort(array);

    //printing the original inputted array
    cout<<"Elements before sorting:\n";
    for(int i:array)
        cout<<i<<" ";

    //printing the sorted formatted array
    cout<<"\nElements after sorting:\n";
    for(int i:sortedArray)
        cout<<i<<" ";

    return 0;
}