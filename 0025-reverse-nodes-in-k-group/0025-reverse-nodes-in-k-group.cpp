/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* find_kth_node(ListNode* temp,int k){
        k=k-1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse_kth_node(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* new_head= reverse_kth_node(head->next);
        ListNode* front= head->next;
        front->next=head;
        head->next=NULL;
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev_Last=NULL;
        ListNode* nextNode;
        while(temp!=NULL){
            ListNode* kth_Node= find_kth_node(temp,k);
            if(kth_Node==NULL){
                if(prev_Last!=NULL){
                    prev_Last->next=temp;
                }
                break;
            }
            nextNode=kth_Node->next;
            kth_Node->next=NULL;
            ListNode* rev_head= reverse_kth_node(temp);
            if(temp==head){
                head=rev_head;
            }
            else{
                prev_Last->next=rev_head;
            }
            prev_Last=temp;
            temp=nextNode;
        }
        return head;
    }
};