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
    ListNode* find_lastNode(ListNode* head, int len){
        int count=1;
        ListNode* temp=head;
        while(count<len){
            temp=temp->next;
            count++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        int newk= k%len;
        if(newk==0){
            return head;
        }
        tail->next=head;
        ListNode* lastN= find_lastNode(head,len-newk);
        head=lastN->next;
        lastN->next=NULL;
        return head;
        
    }
};