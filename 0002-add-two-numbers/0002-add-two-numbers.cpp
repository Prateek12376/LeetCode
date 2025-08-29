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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1= l1;
        ListNode* temp2=  l2;
        ListNode* dummy_node= new ListNode(0);
        ListNode* current= dummy_node;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum= carry;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            ListNode* new_node= new ListNode(sum%10);
            carry = sum/10;
            current->next= new_node;
            current=current->next;
        }
        if(carry>0){
            ListNode* carry_node= new ListNode(carry);
            current->next=carry_node;
        }
        return dummy_node->next;
    }
};