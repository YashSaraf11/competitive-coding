// URL : https://leetcode.com/problems/container-with-most-water/submissions/

class Solution {
public:
    int maxArea(vector<int>& height) {
        //two-pointer problem so we put pointers at the extremes
        int start=0,end=height.size()-1;
        
        int max_area=0;
        while(start<end){            
            //we calculate max area between the two bars 
            max_area=max(max_area,(end-start)*min(height[start],height[end]));
            
            //we shift the pointer with the lower height to see if there's better area possible
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};