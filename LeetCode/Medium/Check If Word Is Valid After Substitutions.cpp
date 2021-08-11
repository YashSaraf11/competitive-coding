// URL : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(char ch:s){
            if(ch=='c' && st.size()>=2 && st[st.size()-1] =='b' && st[st.size()-2]=='a'){
                st.resize(st.size()-2);
            }
            else
                st.push_back(ch);
        }
        return st.size()==0;
    }    
};

/*
This problem looks similar to the simultaneous frogs croaking,i.e.
                        (https://leetcode.com/problems/minimum-number-of-frogs-croaking/)
but is different since we can add the elements i                    
                        

*/