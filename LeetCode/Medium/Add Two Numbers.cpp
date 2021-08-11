//URL : https://leetcode.com/problems/add-two-numbers/solution/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Creating a new list to store the sum of the lists
        ListNode *dummyHead= new ListNode(0);
        //Created a dummyhead to break from the hassle of managing the head node seprately
        ListNode *currNode = dummyHead;
        
        //variable to store the carry generated from the sum of the previous iteration
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry){
            
            //storing the value as 0 if the pointer is null
            int val_l1 = (l1)? l1->val : 0;
            int val_l2 = (l2)? l2->val : 0;
                        
            currNode->next = new ListNode((val_l1+val_l2+carry)%10);
            carry= (val_l1+val_l2+carry)/10;
            
            //checking if the pointer is not null then to pass on to the next node in the list
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            currNode=currNode->next;
        }
        
        //returning the head of the actual list created
        return dummyHead->next;
    }
};

/*
Creating of a dummyhead in questions of lists helps a lot as it helps and saves you from the
hassle of managing the head node seprately and only O(1) space extra is used as we create 
only one extra node
*/