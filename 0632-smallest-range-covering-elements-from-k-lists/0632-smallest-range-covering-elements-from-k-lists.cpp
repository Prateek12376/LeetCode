struct node{
public:
    int val;
    int row;
    int col;
    node(int value,int i,int j){
        val=value;
        row=i;
        col=j;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,node*>,vector<pair<int,node*>>,greater<pair<int,node*>>>pq;
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
            node* temp= new node(nums[i][0],i,0);
            mini=min(mini,temp->val);
            maxi=max(maxi,temp->val);
            pq.push({temp->val,temp});
        }
        int start=mini,end=maxi;
        while(!pq.empty()){
            node* temp=pq.top().second;
            pq.pop();
            mini=temp->val;

            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }
            int i=temp->row;
            int j=temp->col;

            if(j+1<nums[i].size()){
                node* next= new node(nums[i][j+1],i,j+1);
                maxi=max(maxi,next->val);
                pq.push({next->val,next});
            }
            else{
                break;
            }
        }
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};