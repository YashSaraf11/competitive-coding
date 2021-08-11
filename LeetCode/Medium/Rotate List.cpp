// URL : https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        //base condition to return
        if(head==0 || k==0)
            return head;
        
        //new dummynode to keep the nodes in the rotated order        
        ListNode *d1 = new ListNode(0);
        //pointers to traverse and track the nodes in the lists
        ListNode *h=head, *nH=head, *rH=d1;
        
        //calculating the size of the list given
        int size=0;
        while(h!=nullptr){
            size++;
            h=h->next;
        }        
        
        //calculating the actual number of nodes we need to move in case k>=size
        k%=size;
        //to save from unnecessary computation and shifting incase of k==0 
        if(k==0)
            return head;
        
        //traversing the list till size-k nodes since they will be in same order
        for(int i=1;i<size-k;i++)
            nH=nH->next;                                
        
        //adding the nodes to be rotated to the dummynode 
        rH->next=nH->next;        
        while(rH->next!=nullptr)
            rH=rH->next;
        
        //setting up the end links to the head and nullptr for the start and end of the rotated list
        rH->next=head;
        nH->next= nullptr;       
                        
        return d1->next;        
    }
};