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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * revH = reverseLL(head->next);

        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;

        return revH;
    }
    int pairSum(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* revH = reverseLL(slow);

        ListNode* temp = revH;
        ListNode* t1= head;
        int maxi = INT_MIN;
        while(temp!=NULL){
            int sum  = temp->val+t1->val;
            maxi=max(maxi,sum);
            temp=temp->next;
            t1=t1->next;
        }
        return maxi;
    }
};