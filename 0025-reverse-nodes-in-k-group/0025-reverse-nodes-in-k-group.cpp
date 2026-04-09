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
    ListNode* find_kth(ListNode* head, int k){
        k=k-1;
        while(head!=NULL && k>0){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* reverseN(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* reverseH  = reverseN(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;
        return reverseH;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head;
       ListNode* prevN=NULL;
       ListNode* nextN;
       while(temp!=NULL){
            ListNode* kth_node =  find_kth(temp,k);
            if(kth_node==NULL){
                if(prevN!=NULL){
                    prevN->next=temp;
                }
                break;
            }
            nextN=kth_node->next;
            kth_node->next=NULL;
            ListNode* reverseH= reverseN(temp);

            if(temp==head){
                head=reverseH;
            }
            else{
                prevN->next=reverseH;
            }
            prevN=temp;
            temp=nextN;
        }
        return head;
    }
};