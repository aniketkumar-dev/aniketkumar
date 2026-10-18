/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        Node* curr = head;        
        
        
        while(curr != NULL){
            if(curr->child != NULL){
                Node* nextNode = curr->next;
                Node* childNode = flatten(curr->child);
             // step 1 curr ke baad child ko add krna hai 
            curr->next = childNode;
            childNode->prev = curr;

            // chldNode ko end tak le ao
            Node* tail = childNode;
            while(tail->next != NULL){
                tail = tail->next;
            }

            curr->child = NULL;
            
            // ab tail ko connect kr do nextnode se
            tail->next = nextNode;

            if(nextNode != NULL){
                nextNode->prev = tail;
            }


            }
            curr = curr->next;

        }

      return head; 
        
    }

};