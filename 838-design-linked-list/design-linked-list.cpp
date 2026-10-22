
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        ListNode* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = head;
        head = newHead;
        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        ListNode* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        ListNode* target = curr->next;
        curr->next = target->next;
        delete target;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index, val);
 * obj->deleteAtIndex(index);
 */
