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
        if(head==NULL){
            return NULL;
        }
        Node* curr = head;
        while(curr!=NULL){
            if(curr->child){
                Node* nextNode= curr->next;
                curr->next= flatten(curr->child);
                curr->next->prev=curr;
                curr->child=NULL;

                while(curr->next!=NULL){
                    curr=curr->next;
                }
                if(nextNode!=NULL){
                    curr->next=nextNode;
                    nextNode->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};