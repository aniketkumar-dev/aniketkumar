class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        if(head->next == NULL) return head;

        // Starting duplicate groups
        while(head != NULL && head->next != NULL &&
              head->val == head->next->val) {

            int value = head->val;

            while(head != NULL && head->val == value) {
                head = head->next;
            }
        }

        if(head == NULL) return NULL;

        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp != NULL) {

            if(temp->next != NULL && temp->val == temp->next->val) {

                int value = temp->val;

                while(temp != NULL && temp->val == value) {
                    temp = temp->next;
                }

                prev->next = temp;

            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};