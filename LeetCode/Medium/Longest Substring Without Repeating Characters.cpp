//URL : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //vector to store the count of characters-256 to store the symbols and digits
        vector<int> count(256,0);
        
        /*variables to store the max length of the substring and 
          the startIndex of the previously encountered longest substring*/  
        int maxLen=0,startIndex=0;
        
        for(int i=0;i<s.length();i++){
            /*we check if the count of the character encountered is >0,
                because its a post increment */
            if(count[s[i]]++){
                //we store the longest encountered substring
                maxLen=max(maxLen,i-startIndex);
                
                /*we then remove the elements from the virtual substring
                    till the count of the character at ith index is ==1 */            
                while(startIndex<i && count[s[i]]>1)
                    count[s[startIndex++]]--;                                
            }
        }
        /*to see if there was no repeating character till the end of the list 
            after its first encounter of repeated character*/
        return max(maxLen,(int)s.length()-startIndex);
    }
};

/*
Here, the virtual string doesn't mean anything but that we haven't stored the string in any variable but we are keeping the track of the string
through the startIndex and the count vector , if a count[ch]>0 then we know we already have that character in the virtual string and we need to delete all the characters
and their count till the count[ch]==0.

This problem is a Sliding Window Problem , where we move the window when we encounter an already encountered character in the virtual string
*/