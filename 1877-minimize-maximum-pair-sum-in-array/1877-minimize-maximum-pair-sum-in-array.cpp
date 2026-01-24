class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n/2;i++){
            int sum=nums[i]+nums[n-i-1];
            ans=max(ans,sum);
            
        }
        return ans;
    }
};