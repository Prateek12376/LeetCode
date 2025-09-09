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
    ListNode* swapPairs(ListNode* head) {
         if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp= head;
        ListNode* dummy_node = new ListNode(-1);
        ListNode* prevNode= dummy_node;
        ListNode* nextNode= temp->next;
        while(temp!=NULL && temp->next!=NULL){
            ListNode* first= temp;
            ListNode* second= temp->next;

            first->next=second->next;
            second->next=first;
            prevNode->next=second;

            prevNode= first;
            temp=first->next;
        }
        return dummy_node->next;
    }
};