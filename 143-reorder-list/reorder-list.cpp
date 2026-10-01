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

 ListNode* reverse(ListNode* temp ){
    // reverse 
    ListNode* temp1 = temp;
    ListNode* prev = NULL;
    while(temp1 != NULL){
        ListNode* next = temp1->next;
        temp1->next =  prev;
        prev = temp1;
        temp1 = next;

    }
    return prev;
 }
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return ;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;


        }

        ListNode* mid = slow;
        ListNode* temp = mid->next;
        mid->next = NULL;
       ListNode* second =  reverse(temp);

        
        // connect kr denge hmm
        ListNode* first = head;
        while(second != NULL){
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            first->next = second;

            second->next = next1;

            first = next1;
            second = next2;

        }
        return;


    }
};