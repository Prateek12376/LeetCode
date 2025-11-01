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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>set1;
        if(head==NULL){
            return NULL;
        }
        for(int i=0;i<nums.size();i++){
            set1.insert(nums[i]);
        }
        while(head!=NULL && set1.count(head->val)){
            head=head->next;
        }
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp!=NULL){
            while(temp!=NULL && set1.count(temp->val)){
                temp=temp->next;
            }
            prev->next=temp;
            if(temp!=NULL){
                prev=prev->next;
                temp=temp->next;
            }
        }
        return head;
    }
};