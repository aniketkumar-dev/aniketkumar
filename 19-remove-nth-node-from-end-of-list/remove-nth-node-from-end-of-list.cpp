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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int k = cnt - n ;
        if(cnt == n){
            return head->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(k > 0){
            prev = curr;
            curr = curr->next;
            k--;

        }
        // prev ->next = curr->next;
        prev->next = curr->next;
        return head;

    }
};