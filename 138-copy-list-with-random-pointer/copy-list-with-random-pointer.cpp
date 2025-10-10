/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return head;

        // insert new nodes in between original linked list

        Node* curr = head;
        while(curr){
            Node* tosave = curr->next; //B
            curr->next = new Node(curr->val);//A->x
            curr->next->next = tosave;//A->x->B
            curr = tosave;
        }
        curr = head;
        //Deep copy of random pointers

        while(curr){
            if(curr->random==NULL){
                curr->next->random=NULL;
            }else{
                curr->next->random = curr->random->next;
            }

            curr = curr->next==NULL?NULL:curr->next->next;
        }
        //Seperate Linked list

        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;

        while(curr && newCurr){
            curr->next = (curr->next==NULL)?NULL:curr->next->next;
            newCurr->next = (newCurr->next==NULL)?NULL:newCurr->next->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};