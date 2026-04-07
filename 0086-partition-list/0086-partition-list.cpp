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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* lessH = new ListNode(0);
        ListNode* greaterH = new ListNode(0);

        ListNode* less = lessH;
        ListNode* greater= greaterH;

        while(head!=NULL){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=NULL;
        less->next=greaterH->next;

        return lessH->next;
    }
};