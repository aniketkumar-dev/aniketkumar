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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int val1 = 0;
            int val2 = 0;
            if(temp1 != NULL){
                val1 = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                val2 = temp2->val;
                temp2 = temp2->next;
            }

            int sumTemp = val1 + val2 + carry;
            int ans  = sumTemp % 10;
              carry = sumTemp / 10;
             ListNode* temp = new ListNode(ans);
             
             curr->next = temp;
             curr = curr->next;

            

        }

        if(carry != 0){
            curr->next = new ListNode(carry);
        }

        
        return dummyNode->next;
    }
};