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
        if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* revH = reverseLL(head->next);
        ListNode* front= head->next;
        front->next=head;
        head->next=NULL;
        return revH;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* newH= new ListNode(head->val);
        ListNode* curr = head->next;
        ListNode* temp1= newH;
        int count=1;
        while(curr!=NULL){
            count++;
            ListNode* n1 = new ListNode(curr->val);
            temp1->next=n1;
            temp1=temp1->next;
            curr=curr->next;
        }
        ListNode* revH = reverseLL(newH);
        ListNode* temp = head;
        ListNode* revt = revH;
        int lim=(count)/2;
        while(lim>0){
            ListNode* nextNode = temp->next;
            ListNode* n2 = new ListNode(revt->val);
            revt = revt->next;
            temp->next = n2;
            n2->next = nextNode;
            temp = nextNode;
            lim--;
        }
        ListNode* t = head;
        while(t!=NULL && count>1){
            count--;
            t=t->next;
        }
        t->next=NULL;
    }
};