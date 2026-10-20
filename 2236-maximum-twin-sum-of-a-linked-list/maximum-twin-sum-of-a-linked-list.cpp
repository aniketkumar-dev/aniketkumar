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
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
   prev->next = NULL;
   return slow;
}


 ListNode* reverse(ListNode* head){
    ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        return prev;
 }
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* mid = findMid(head);
       ListNode* rev =  reverse(mid);

       // add kr denge hm dono ko or jo max sum dega return kr denge
       int maxi = 0;
       ListNode* temp1 = head;
       ListNode* temp2 = rev;
       while(temp1 != NULL && temp2 != NULL){
            int sum  = temp1->val + temp2->val;
            maxi = max(sum , maxi);
            temp1 = temp1->next;
            temp2  = temp2->next;
       }
       return maxi;
       
       
        
    }
};