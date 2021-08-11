// URL : https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        //stack to store the operators and operands
        stack<char> s;
        
        //traversing the expression
        for(char ch:expression){
            //popping out elements till the operator
            if(ch==')'){
                //checking if the intermediate expression contains true and false
                bool containsTrue=false,containsFalse=false;
                while(s.top()=='t' || s.top()=='f'){
                    if(s.top()=='t')
                        containsTrue=true;
                    else
                        containsFalse=true;                    
                    s.pop();
                }
                //taking the operator to calculate the intermediate result
                char op= s.top();
                s.pop();
                
                //calculating and pushing the intermediate result for further evaluation
                bool result = op=='!'? (containsFalse? true : false ) 
                    : (op=='&' ? (containsFalse? false : true) : (containsTrue? true : false)) ;
                result == true? s.push('t') : s.push('f');
            }
            //pushing characters only if its an operator or t/f
            else if(ch!=',' && ch!='(')
                s.push(ch);
        }
        //returning the final ans stored at the top of stack
        return s.top()=='t' ?true:false;
    }
};