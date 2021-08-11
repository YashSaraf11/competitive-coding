// URL : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        //base condition if the head is nullptr
        if(head==nullptr)
            return head;
        
        //map to store the sum encountered in previous iteration
        unordered_map<int,ListNode*> sumEncountered;
        
        //dummyHead to escape the hassle of handling the head cases seprately
        ListNode *dummyHead= new ListNode(0);        
        ListNode *currNode=dummyHead;
        
        //appending the list to the dummyhead
        dummyHead->next=head;
        int sum=0;
        
        while(currNode){
            //calculating the sum of the nodes
            sum+=currNode->val;
            
            //if we have encountered the sum before then we need to remove those extra nodes
            if(sumEncountered[sum]){
                currNode = sumEncountered[sum]->next;
                
                int prefix= sum+ currNode->val;            
                //traversing till the sum and prefix becomes same
                while(prefix!=sum){
                    sumEncountered.erase(prefix);
                    currNode=currNode->next;
                    prefix+=currNode->val;
                }                
                //fixing the links to the next of the currNode pointer
                sumEncountered[prefix]->next=currNode->next;
            }
            else{
                //if we don't encounter the sum then we add the sum and node to the map
                sumEncountered[sum]=currNode;
            }        
            currNode=currNode->next;
        }        
        return dummyHead->next;
    }
};

/*
Using the dummyHead saves from the hassle of handling the case of the head pointer/node differntially and makes the code easy and short
So try to use it as much as you can
*/