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
    ListNode* find_middle(ListNode* head){
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* head1, ListNode* head2){
        ListNode* dummy_node= new ListNode(-1);
        ListNode* temp= dummy_node;
        while(head1!=NULL && head2!=NULL){
            if(head1->val > head2->val){
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
            else{
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
        }
        if(head1!=NULL){
            temp->next=head1;
            temp=head1;
            head1=head1->next;
        }
         if(head2!=NULL){
            temp->next=head2;
            temp=head2;
            head2=head2->next;
        }
        return dummy_node->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle= find_middle(head);
        ListNode* left= head;
        ListNode* right= middle->next;
        middle->next=nullptr;
        left= sortList(left);
        right=sortList(right);
        ListNode* sort_head= mergeLL(left,right);
        return sort_head;
    }
};