
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if (head == nullptr) return nullptr;

        head = reverse(head);

        ListNode* curr = head;
        int carry = 0;

        while (curr != nullptr) {
            int num = curr->val * 2 + carry;

            curr->val = num % 10;
            carry = num / 10;

            if (curr->next == nullptr) {
                if (carry > 0) {
                    curr->next = new ListNode(carry);
                }
                break;
            }

            curr = curr->next;
        }

        return reverse(head);
    }
};
