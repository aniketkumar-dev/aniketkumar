class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;

        
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = NULL;

       
        while(!s1.empty() || !s2.empty() || carry) {

            int val1 = 0;
            int val2 = 0;

            if(!s1.empty()) {
                val1 = s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                val2 = s2.top();
                s2.pop();
            }

            int add = val1 + val2 + carry;

            int ans = add % 10;
            carry = add / 10;

            // Front mein node insert krna hai
            ListNode* res = new ListNode(ans);
            res->next = head;
            head = res;
        }

        return head;
    }
};