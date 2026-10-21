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
         ListNode* dummy = new ListNode(0);
         dummy->next = head;
         ListNode* curr = dummy;
         unordered_map<int, ListNode*>mpp;
         int sum = 0;
         while(curr != NULL){
            sum += curr->val;
            mpp[sum] = curr;
            curr = curr->next;
         }

         curr = dummy;
         sum = 0;
         while(curr != NULL){
            sum += curr->val;
           ListNode* temp =  mpp[sum];
           curr->next = temp->next;
           curr = curr->next;
         }
         return dummy->next;




    }
};