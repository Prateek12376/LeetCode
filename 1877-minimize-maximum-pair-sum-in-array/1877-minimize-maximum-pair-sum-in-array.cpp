class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        priority_queue<int,vector<int>,less<int>>pq;
        for(int i=0;i<n;i++){
            int sum=nums[i]+nums[n-i-1];
            pq.push(sum);
        }
        return pq.top();
    }
};