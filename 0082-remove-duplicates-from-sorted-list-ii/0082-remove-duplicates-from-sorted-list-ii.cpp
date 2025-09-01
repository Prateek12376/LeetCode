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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy_node= new ListNode(-1);
        dummy_node->next=head;
        ListNode* prev =dummy_node;
        ListNode* current= head;
        while(current!=NULL && current->next!=NULL){
            if(current->val ==current->next->val){
                while(current->next!=NULL && current->val==current->next->val){
                    current=current->next;
                }
                prev->next=current->next;
            }
            else{
                prev= prev->next;
            }
            current=current->next;
        }
        return dummy_node->next;
    }
};