class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        while(k>0){
            int q= pq.top();
            pq.pop();
            k--;
            if(k==0){
                return q;
            }
        }
        return{};
        
    }
};