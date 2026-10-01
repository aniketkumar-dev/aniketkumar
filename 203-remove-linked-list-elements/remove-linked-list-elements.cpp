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
    ListNode* removeElements(ListNode* head, int val) {

        // zero
        if(head == NULL ) return NULL;
    // single
        if(head->next == NULL){
            if(head->val == val) return NULL;
        }
        // multiple starting ke liye
        while(head != NULL && head->val == val) {
        head = head->next;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* next = curr->next;
            if(curr->val == val){
                prev->next = next;
                curr = next;
            }else{
                prev = curr;
                curr = next;
            }

        }
        return head;
        
    }
};