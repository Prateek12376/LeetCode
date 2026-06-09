class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long maxi= LLONG_MIN;
        long long mini= LLONG_MAX;
        for(int i=0;i<n;i++){
            long long num=1LL*nums[i];
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        return (maxi-mini)*k;
    }
};