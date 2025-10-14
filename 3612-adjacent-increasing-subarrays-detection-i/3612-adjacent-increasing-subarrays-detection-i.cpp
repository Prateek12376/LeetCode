class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>length(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                length[i]=length[i-1]+1;
            }
        }
        for(int i=0;i<=n-2*k;i++){
            if(length[i+k-1]>=k && length[i+2*k-1]>=k){
                return true;
                break;
            }
        }
        return false;
    }
};