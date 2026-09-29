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
        if(head == NULL || head->next == NULL) return head;
         ListNode* prev = NULL;
        ListNode* curr = head;

        int count = 1;
        while(count < left){
            prev = curr;
            curr = curr->next;
            count++;

        }
       
       ListNode* temp1 = prev;
       ListNode* temp2 = curr;
       
        prev = NULL;
        while(count <= right){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            count++;
            
        }

        temp2->next = curr;

        if(temp1 != NULL)
            temp1->next = prev;
        else
            head = prev;
        return head;

       

    

        
    }
};