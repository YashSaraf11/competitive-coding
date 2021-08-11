
#include<bits/stdc++.h>
using namespace std;

/*selection sort function:
    in selection sort we select the min/max element and put it at the last/first position of the array depending upon the 
    order in which we are sorting and similarly we move to the next iteration where we put the min/max element at the second last/first position
    and we keep on proceeding and thus at the end of the operation we get a sorted array

    the complexity of selection sort is O(N^2) and thus its usually not preferrable to use but it takes O(1) constant space complexity    
*/
vector<int> selection_sort(vector<int> unsorted_array){ 
    //here we are sorting in the descending order
    for(int i=0;i<unsorted_array.size()-1;i++){
        int max_index=i;
        for(int j=i+1;j<unsorted_array.size();j++){
            if(unsorted_array[j]>unsorted_array[max_index])
                max_index=j;            
        }
        swap(unsorted_array[i],unsorted_array[max_index]);
    } 

    /*the code for sorting in the ascending order has just one change that is we need to find the minium element    
        so just change the if condition to (unsorted_array[j]<unsorted_array[min_index]) 
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
    vector<int> sortedArray = selection_sort(array);

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