class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int len =INT_MAX;

        deque<int>dq;
        int n=nums.size();

        vector<long long>preSum(n);
        preSum[0]=1LL*nums[0];

        if(nums[0]>=k){
            return 1;
        }

        for(int i=1;i<nums.size();i++){
            preSum[i]=1LL*nums[i]+preSum[i-1];

            if(preSum[i]>=k){
                len=min(len,i+1);
            }
        }

        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && preSum[i]<=preSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            while(!dq.empty() && preSum[dq.back()]-preSum[dq.front()]>=k){
                len=min(len,dq.back()-dq.front());
                dq.pop_front();
            }
        }

        
        if(len==INT_MAX){
            return -1;
        }
        return len;
    }
};