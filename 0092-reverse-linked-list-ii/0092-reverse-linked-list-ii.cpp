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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right){
            return head;
        }
        ListNode*  dummy_node= new ListNode (-1);
        dummy_node->next=head;
        ListNode* prev= dummy_node;
        ListNode* curr;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        curr=prev->next;
        for(int i=left;i<right;i++){
            ListNode* temp= curr->next;
            curr->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;    ;
        }
        return dummy_node->next;

    }
};