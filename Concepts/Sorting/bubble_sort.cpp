#include<bits/stdc++.h>
using namespace std;

/*bubble sort function:
    in bubble sort we compare the adjacent elements in the array and then swap them on the condition that we want max/min ordered array
    we run the outer loop array.size-1 times and the inner loop array.size-i-1 times as we know the last i elements in the array are already sorted
    so we don't need to compare them.

    the complexity of selection sort is O(N^2) and thus its usually not preferrable to use but it takes O(1) constant space complexity    
*/
vector<int> bubble_sort(vector<int> unsorted_array){
    //here we are sorting in the descending order
    for(int i=0;i<unsorted_array.size()-1;i++){
        for(int j=0;j<unsorted_array.size()-i-1;j++){
            if(unsorted_array[j]<unsorted_array[j+1])
                swap(unsorted_array[j],unsorted_array[j+1]);
        }
    }

     /*the code for sorting in the ascending order has just one change that is we need to find the minium element between the two
        so just change the if condition to (unsorted_array[j]>unsorted_array[j+1]) 
        we get the minimum value everytime and thus we get an ascending ordered array
    */
    return unsorted_array;
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
    vector<int> sortedArray = bubble_sort(array);

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