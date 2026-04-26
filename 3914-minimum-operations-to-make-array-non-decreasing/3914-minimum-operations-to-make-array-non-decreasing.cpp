class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long x=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(nums[i]<nums[i-1]){
                    x+=(nums[i-1])-(nums[i]);
                }
                
            }
        }
        return x;
    }
};