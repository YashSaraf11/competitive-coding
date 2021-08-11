//Assuming we are given a big dataset between 0.0 and 1.0 and is distributed uniformly 
#include<bits/stdc++.h>
using namespace std;

vector<double> bucket_sort(vector<double> array){
    //creating n empty bucket
    vector<vector<double>> bucket(array.size());

    //pushing the element of the array into ith bucket based on their value
    for(auto i:array){
        int index= array.size() * i;
        bucket[index].push_back(i);
    }

    //sorting the individual buckets
    for(int i=0;i<array.size();i++)
        sort(bucket[i].begin(),bucket[i].end());

    //putting the elements in the array in the sorted ordered form
    int index=0;
    for(int i=0;i<array.size();i++){
        for(int j=0;j<bucket[i].size();j++)
            array[index++]=bucket[i][j];
    }
    return array;
}

int main(){
    //taking input of number of elements to sort
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    //taking input of the elements to sort
    vector<double> array(n);
    cout<<"Enter "<<n<<" elements:\n";       
    for(int i=0;i<n;i++)        
        cin>>array[i];

    //the sorted array returned is stored into the vector(sortedArray)
    vector<double> sortedArray = bucket_sort(array);

    //printing the original inputted array
    cout<<"Elements before sorting:\n";
    for(auto i:array)
        cout<<i<<" ";

    //printing the sorted formatted array
    cout<<"\nElements after sorting:\n";
    for(auto i:sortedArray)
        cout<<i<<" ";

    return 0;
}