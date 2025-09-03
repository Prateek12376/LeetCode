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
    void copy_ofList(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy_node= new Node(temp->val);
            copy_node->next=temp->next;
            temp->next=copy_node;
            temp=temp->next->next;
        }
    }
    void join_randomPointer(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy_node= temp->next;
            if(temp->random!=NULL){
                copy_node->random=temp->random->next;
            }
            else{
                copy_node->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* join_next_and_extract(Node* head){
        Node* dummy_node=new Node(-1);
        Node* curr= dummy_node;
        Node* temp=head;
        while(temp!=NULL){
            curr->next=temp->next;
            temp->next=temp->next->next;
            curr=curr->next;
            temp=temp->next;
        }
        return dummy_node->next;
    }
    Node* copyRandomList(Node* head) {
        copy_ofList(head); 
        join_randomPointer(head);
        Node* head_copyLL= join_next_and_extract(head);
        return head_copyLL;
    }
};