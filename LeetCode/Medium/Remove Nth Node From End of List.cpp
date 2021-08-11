// URL : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //creating a dummy node to save from hassle of handling head cases
        ListNode *dummyHead = new ListNode(0);
        //pointing the next of the dummyhead to the head of the list
        dummyHead->next=head;
        
        //moving the fastPointer 'n' nodes ahead
        ListNode *slowPointer=dummyHead,*fastPointer=dummyHead;        
        for(int i=0;i<=n;i++)
            fastPointer=fastPointer->next;
        
        /*now traversing the fastPointer till its null,
            when the fastPointer will be null the slowPointer will be pointing to the node
                previous to the one we want to delete, because they are 'n' nodes apart */
        while(fastPointer!=nullptr){
            fastPointer=fastPointer->next;
            slowPointer=slowPointer->next;
        }
        
        //removing the pointer from the list 
        slowPointer->next=slowPointer->next->next;
        return dummyHead->next;
    }
};