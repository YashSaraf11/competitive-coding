//URL : https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {        
        //map data structure to store the index of the value at ith index
        unordered_map<int,int> position;
        for(int i=0;i<nums2.size();i++){
            position[nums2[i]]=i;
        }
        
        //stack to find out the next greater element in the order
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            int currVal=nums2[i];            
            while(s.size() && s.top()<=nums2[i])
                s.pop();            
            nums2[i]= s.empty()? -1 : s.top();
            s.push(currVal);
        }
        
        /*using the map to find the value of the index in nums2 vector
            and storing the value in nums1*/
        for(int i=0;i<nums1.size();i++){
            nums1[i] = nums2[position[nums1[i]]];
        }
        
        return nums1;
    }
};