class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxE=max(maxE,nums[i]);
        }
        int l=0;
        int r=0;
        int cnt=0;
        long long ans=0;
        while(r<nums.size()){
            if(nums[r]==maxE){
                cnt++;
            }
            while(cnt>=k){
                ans+=(nums.size()-r);

                if(nums[l]==maxE){
                    cnt--;
                }
                l++;
            }
            r++;

        }
        return ans;
    }
};