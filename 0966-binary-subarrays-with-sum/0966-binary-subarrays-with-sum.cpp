class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int right=0;
        int left=0;
        long long count=0;
        long long sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+= (right-left+1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        long long count= atMost(nums,goal)- atMost(nums,goal-1);
        return (int)count;
    }
};