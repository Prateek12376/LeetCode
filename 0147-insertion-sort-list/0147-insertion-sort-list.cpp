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
        ListNode* newh= new ListNode(-1);
        ListNode* t1 = newh;
        ListNode* temp= head;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            ListNode* n1= new ListNode(arr[i]);
            t1->next=n1;
            t1=t1->next;
        }
        t1->next=NULL;
        return newh->next;
    }
};