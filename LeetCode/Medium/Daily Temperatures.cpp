// URL : https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack of pairs to store the index & tempeature value
        stack<pair<int,int>> s;    
        
        for(int i=temperatures.size()-1;i>=0;i--){
            /*since we are modifying the temperature vector itself and not using a new vector
                we need to store the current index value*/
            int currVal=temperatures[i];
            
            //popping out the stack elements until the element in stack has greater temperature
            while(s.size() && s.top().first<=temperatures[i])
                s.pop();
            
            //changing the value of temperature based on the stack size
            temperatures[i] = s.empty() ? 0 : s.top().second-i;
            
            //pushing the current index value to the stack for remaining processing
            s.push({currVal,i});
        }
        return temperatures;
    }
};