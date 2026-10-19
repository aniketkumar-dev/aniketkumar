
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* curr = head;
        int size = 0;

        while (curr != NULL) {
            size++;
            curr = curr->next;
        }

        int part = size / k;
        int rem = size % k;

        vector<ListNode*> ans;

        // Case 1: size < k
        if (size < k) {
            while (head != NULL) {
                ans.push_back(head);

                ListNode* nextNode = head->next;
                head->next = NULL;
                head = nextNode;
            }

            while (ans.size() < k) {
                ans.push_back(NULL);
            }

            return ans;
        }

        // Case 2: size >= k
        curr = head;

        for (int i = 0; i < k; i++) {
            int len = part;

            if (rem > 0) {
                len++;
                rem--;
            }

            ans.push_back(curr);

            for (int j = 1; j < len; j++) {
                curr = curr->next;
            }

            ListNode* nextNode = curr->next;
            curr->next = NULL;
            curr = nextNode;
        }

        return ans;
    }
};
