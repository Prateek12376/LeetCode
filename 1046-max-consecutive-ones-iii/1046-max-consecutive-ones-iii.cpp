class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int n=nums.size();
        int maxLen=0;
        int zero_c=0;
        while(right<n){
            if(nums[right]==0){
                zero_c++;
            }
            if(zero_c>k){
                if(nums[left]==0){
                    zero_c--;
                }
                left++;
            }
            if(zero_c<=k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};