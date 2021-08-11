// URL : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string number) {
        //base condition to return if string is empty
        if(number.length()<1)
            return {};
        
        //storing the characters on a digit on a phone
        string digits[]=
        {
            "","","abc",
            "def","ghi","jkl",
            "mno","pqrs","tuv","wxyz"
            };
        
        //variable to store the result
        vector<string> result;
        
        //calling the backtracking function to store all the combinations
        backtracking(result,"",digits,number,0);
        
        return result;
    }
    
    void backtracking(vector<string>& result,string currString,string digits[],string number,int index){
        //base condition to stop and store into result
        if(index==number.length()){
            result.push_back(currString);
            return;
        }
        
        //recursively calling and adding all the combinations
        for(int i=0;i<digits[number[index]-'0'].length();i++){
            backtracking(result,currString+digits[number[index]-'0'][i],digits,number,index+1);
        }
            
    }
};