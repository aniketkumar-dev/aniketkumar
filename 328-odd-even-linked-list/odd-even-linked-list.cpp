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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
      
        ListNode* oddDummyNode = new ListNode(-1);
        ListNode* evenDummyNode = new ListNode(-1);

        ListNode* oddNode = oddDummyNode;
        ListNode* evenNode = evenDummyNode;
        ListNode* temp = head;
        int pos = 1;
        while(temp != NULL){
            if(pos % 2 != 0){
                // odd
                oddNode->next = temp;
                
                oddNode = oddNode->next;
            }else{
                // even;
                evenNode->next = temp;
                
                evenNode = evenNode->next;

            }
            temp = temp->next;
            pos++;
           
            
        }
         oddNode->next = evenDummyNode->next;
         evenNode->next = NULL;
         return oddDummyNode->next;
    }
};