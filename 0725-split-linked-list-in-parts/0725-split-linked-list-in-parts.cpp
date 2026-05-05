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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,NULL);
        int ind=0;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int size=n/k;
        int extra=n%k;
        temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL){
                break;
            }
            ans[i]=temp;
            int currS= size;
            if(extra>0){
                extra--;
                currS+=1;
            }
            for(int j=1;j<currS;j++){
                temp=temp->next;
            }
            ListNode* nextP= temp->next;
            temp->next=NULL;
            temp=nextP;
        }
        return ans;  
        
    }
};