/*
    Leetcode : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    GFG : https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //storing the characters a phone digit can be used to type
        vector<string> phoneNumber{
            "","","abc",
            "def","ghi","jkl",
            "mno","pqrs","tuv","wxyz"
        };
        
        //vector to store the result
        vector<string> result;
        //calling the backtracking function to store the combinations in the result(vector)
        backtrack(a,phoneNumber,result,"",0,N);
        
        return result;
    }
    
    //Function to backtrack all the possible combinations of letters of the phone number
    void backtrack(int a[],vector<string> phoneNumber,vector<string> &result,string currentStr,int index,int size){
        //base condition to end the backtrack recursion
        if(index==size){
            result.push_back(currentStr);
            return;
        }
        
        //traversing through all the characters a particular digit provides,for example -> '1' gives 'abc'
        for(int i=0;i<phoneNumber[a[index]].size();i++)
            //calling the backtrack function recursively for all those characters individually to get all the combinations
            backtrack(a,phoneNumber,result,currentStr+phoneNumber[a[index]][i],index+1,size);
        
    }
};

int main() {  
    int N;
    cout<<"Enter the size of array:";
    cin >> N; 
    
    int a[N];
    cout<<"Enter "<<N<<"  array elements::\n";
    for(int i =0;i<N;i++){
        cin >> a[i]; 
    }
    
    Solution obj;
    vector <string> res = obj.possibleWords(a,N);
    
    //pringing all the possible combinations
    for (string i : res) cout << i << " ";
    cout << endl;
    
	return 0;
}  