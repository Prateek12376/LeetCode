class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        long long sum=0;
        int l=0;
        int maxF=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while((long long)nums[i]*(i-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }
            maxF=max(maxF,i-l+1);
        }
        return maxF;
    }
};