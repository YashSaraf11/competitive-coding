//URL : https://leetcode.com/problems/next-greater-node-in-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //converting the list to vector since we need to reverse the list
        vector<int> res;
        while(head!=nullptr){
            res.push_back(head->val);
            head=head->next;
        }
        
        //stack to store the higher value
        stack<int> s;
        for(int i=res.size()-1;i>=0;i--){
            //variabe to store the current index value to push to the stack at the end
            int currVal=res[i];
            //popping out the elements in the stack till an higher value is encountered
            while(!s.empty() && s.top()<=res[i])
                s.pop();
                        
            //if the stack is empty then we change the value 0 , otherwise to the element at the top of stack
            res[i] = (s.empty()) ? 0 : s.top();
            
            //pushing the value of the node in the list to the stack for remaining nodes
            s.push(currVal);
            
        }        
        return res;
    }
};


/*
We can reverse the list and then use the stack apporach in a similar way
but since we need to return an array/vector its better to convert the list into a vector
and then traverse it from the back and then modify the value of the vector itself

Its similar to problems like
Daily Tempearture

Next Greater Element

*/