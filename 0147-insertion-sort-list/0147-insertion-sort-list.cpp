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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyN= new ListNode(-1);
        ListNode* temp= head;
        while(temp!=NULL){
            ListNode* prev=dummyN;
            ListNode* nextN=temp->next;

            while(prev->next!=NULL && prev->next->val<temp->val){
                prev=prev->next;
            }
            temp->next=prev->next;
            prev->next=temp;
            temp=nextN;
        }
        return dummyN->next;
        
    }
};