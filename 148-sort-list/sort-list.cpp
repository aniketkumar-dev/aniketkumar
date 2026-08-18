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
 ListNode* middle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
 }

 ListNode* merge(ListNode* first, ListNode* second){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(first != NULL && second != NULL){
        if(first->val <= second->val){
        temp->next = first;
        first = first->next;
    }else{
        temp->next = second;
        second = second->next;
    }
    temp = temp->next;
    }

    if(first != NULL){
        temp->next = first;
    }

    if(second != NULL){
        temp->next = second;
    }
    return dummyNode->next;


 }

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // base case
        if(head == NULL || head->next == NULL) return head;
        ListNode* firstHead = head;
        
        ListNode* Middle = middle(head);

        // divide krna hai mujhe 
            
            ListNode* secondHead = Middle->next;
            Middle->next = NULL;
            
        //  sort
        ListNode* first  = sortList(firstHead);
        ListNode* second  = sortList(secondHead);

        // merge
        return merge(first, second);

        




        

    }
};