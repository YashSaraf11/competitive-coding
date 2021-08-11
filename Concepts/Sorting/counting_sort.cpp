#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

/*count sort function:
    counts the occurence of the elements in the array and stores in the count vector 
    and then we add the value at the previous index that gives us the actual position in the array
    we reiterate over the unsorted_array elements and adds them to the sorted array at their correct position using the value at the count vector
     */
vector<int> count_sort(vector<int> unsorted_array){
    //vector to store the final sorted array
    vector<int> sorted_array(unsorted_array.size());
    
    //vector to store the count of the elements
    vector<int> count(MAX+1,0);

    //counting the elemetns in the vector
    for(int i:unsorted_array)
        count[i]++;
    
    //adding the value at the previous index to get the actual position at the array
    for(int i=1;i<=MAX;i++)
        count[i]+=count[i-1];

    //storing the element at its correct place in the sorted array
    for(int i=0;i<unsorted_array.size();i++){
        sorted_array[count[unsorted_array[i]]-1] = unsorted_array[i];
        --count[unsorted_array[i]];
    }
    return sorted_array;
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
    vector<int> sortedArray = count_sort(array);

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