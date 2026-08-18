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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = temp1->next;

        ListNode* newHead = temp2;
        ListNode* prev = NULL;
        while(temp1 != NULL && temp1->next != NULL ){
            temp2 = temp1->next;
            // swap 
            temp1->next = temp2->next;
            temp2->next = temp1;

            if(prev != NULL) {
                prev->next = temp2;
            }

            // new pair
             prev = temp1;
             temp1 = temp1->next;

            


        }
        return newHead;
         
    }
};