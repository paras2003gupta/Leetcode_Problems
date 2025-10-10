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
        if(head==NULL)return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        unordered_map<Node*,Node*>mp;
        while(curr){
            Node* temp  = new Node(curr->val);
            mp[curr] = temp;
            if(newHead == NULL){
                newHead = temp;
                prev = newHead;
            }
            else{
                prev->next = temp;
                prev = temp;
            }


            curr = curr->next;
        }

        //fill random pointers;
        curr=  head;
        Node *curr1 = newHead;
        while(curr){
            curr1->random = mp[curr->random];
            curr1 = curr1->next;
            curr = curr->next;
        }

        return newHead;


    }
};