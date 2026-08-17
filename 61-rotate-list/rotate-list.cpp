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
        
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        
         ListNode* oldHead = head;       

        int cnt = 0;
        while(temp != NULL){
            
            cnt++;
            temp = temp->next;
        }
        // count nikal liye and sath me 
        k = k % cnt;
        int n = cnt - k;

        if(k == 0) return head;
        ListNode* curr = head;
       
        ListNode* prev = NULL;
        while(n > 0){
            n--;
            prev = curr;
            curr = curr->next;           

        }
        // new head bana liye
        ListNode* newHead = curr;

        prev->next = NULL;

         ListNode* tail = newHead;
         while(tail->next != NULL){
            tail = tail->next;
         }
        // tail ka next old head ke sath
         tail->next = oldHead;
         return newHead;


      
        
    }
};