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
        ListNode* t1= l1;
        ListNode* t2= l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry=0;

        while(l1!=NULL || l2!=NULL){
            int sum= carry;

            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry= sum/10;
            ListNode* newN =  new ListNode(sum%10);

            curr->next=newN;
            curr=curr->next;
        }
        if(carry>0){
            ListNode* newN = new ListNode(carry);
            curr->next=newN;
        }

        return dummy->next;
    }
};