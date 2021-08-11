// URL : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //base condition to return if vector is empty
        if(nums.size()==0)
            return 0;
            
        int maxLen=0,len=1;
        
        //data structure to store the elements in an sorted order without sorting
        set<int> ele(nums.begin(),nums.end());
        
        //iterators to traverse the set
        auto it1=ele.begin();
        for(auto it2=next(it1,1);it2!=ele.end();it2++){            
            //checking if the elements aren't consecutive then we find the maximum length 
            if(*it2-*it1!=1){
                // cout<<*it1<<" "<<*it2<<endl;
                maxLen=max(maxLen,len);
                len=0;                
            }            
            len++;
            it1=it2;
        }    
        return max(maxLen,len);
    }
};