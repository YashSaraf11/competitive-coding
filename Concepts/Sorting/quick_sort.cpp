#include<bits/stdc++.h>
using namespace std;

/*partition function:
    it sorts the array on the basis of pivot element and returns the positio of the pivot element
    and returns the final position of the pivot element*/
int partition(vector<int> &unsorted_array,int left,int right){
    //taking the last element as pivot element
    int pivot=unsorted_array[right];
    
    //index to start storing the elements in the array lower than pivot
    int i=left;
    for(int j=left;j<right;j++){
        if(unsorted_array[j]<=pivot){
            swap(unsorted_array[i++],unsorted_array[j]);
        }
    }
    //swapping the pivot to the position after the elements less than pivot
    swap(unsorted_array[i],unsorted_array[right]);

    //returning the position of the pivot
    return i;
}

/*quicksort function:
    the quicksort function divides the array into 3 parts and recursively sorts the first and last part :
    1->elements lessser than the pivot and sorts it recursively in same way
    2->pivot element itself, which is already in the position it should be
    3->elements greater than the pivot and sorts it recursively in same way*/
void quicksort(vector<int> &unsorted_array,int left,int right){
    //base condition to break the recursive loop
    if(left>=right)
        return;

    //gets the pivot element index from the partition function
    int pivotFinalPosition = partition(unsorted_array,left,right);

    //recursively sorts the two sub arrays, less than pivot and greater than the pivot
    quicksort(unsorted_array,0,pivotFinalPosition-1);
    quicksort(unsorted_array,pivotFinalPosition+1,right);
}

vector<int> quick_sort(vector<int> unsorted_array){    
    quicksort(unsorted_array,0,unsorted_array.size()-1);
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
    vector<int> sortedArray = quick_sort(array);

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