// URL : https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //base condition to return
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *prevNode=dummyHead,*currNode;
        
        //finding the nth(left) node and the node previoius to it
        dummyHead->next=head;
        for(int i=0;i<left-1;i++)
            prevNode=prevNode->next;
        //nth(left) node
        currNode=prevNode->next;
        
        //running the loop till (right-left) times to reverse 2 nodes everytime
        for(int i=1;i<=right-left;i++){
            ListNode *t = prevNode->next;
            prevNode->next = currNode->next;
            currNode->next = currNode->next->next;
            prevNode->next->next = t;
        }
        
        return dummyHead->next;
    }
};