#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &unsorted_array,int l_bound,int mid_bound,int r_bound){

    //size of the two array partitioned
    int size_arr1 = mid_bound-l_bound+1;
    int size_arr2 = r_bound-mid_bound;

    //feeding values into the temporary array to add them back to the main array in sorted order
    vector<int> arr1(size_arr1),arr2(size_arr2); 
    for(int i=0;i<size_arr1;i++)
        arr1[i]=unsorted_array[l_bound+i];        
    for(int i=0;i<size_arr2;i++)
        arr2[i]=unsorted_array[mid_bound+1+i];

    //staring index for the elements to put in order in the original array
    int startIndex=l_bound;

    //adding the values to the main array based on lower/higher value ,i.e, ascending/descending order respectively
    int i=0,j=0;
    while(i<size_arr1 && j<size_arr2){
        if(arr1[i]<arr2[j])
            unsorted_array[startIndex++]=arr1[i++];            
        else
            unsorted_array[startIndex++]=arr2[j++];        
    }
    
    //adding the remaining values if they are of difference sizes
    while(i<size_arr1)
        unsorted_array[startIndex++]=arr1[i++];         
    while(j<size_arr2)
        unsorted_array[startIndex++]=arr2[j++];        

}

/*mergesort function:
    the mergesort function divides the array into two halves recursively and then joins them back in sorted manner*/
void mergeSort(vector<int> &unsorted_array,int l_bound,int r_bound){
    //base condition to exit the recursive loop
    if(l_bound>=r_bound)
        return ;

    //avoid using (l_bound+r_bound)/2 as in large cases it might result in overflow
    int mid_bound = l_bound + (r_bound-l_bound)/2;

    //recursively divide the array into two halves
    mergeSort(unsorted_array,l_bound,mid_bound);
    mergeSort(unsorted_array,mid_bound+1,r_bound);
    
    //merging the two halves into a single array
    merge(unsorted_array,l_bound,mid_bound,r_bound);
}

vector<int> merge_sort(vector<int> unsorted_array){
    mergeSort(unsorted_array,0,unsorted_array.size()-1);    
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