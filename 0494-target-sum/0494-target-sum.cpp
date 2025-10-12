class Solution {
public:
    int find_ways(int index,vector<int>& nums, int target, int curr_sum){
        if(index==nums.size()){
            if(curr_sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int add_one = find_ways(index+1,nums,target,curr_sum+nums[index]);
        int sub_one=  find_ways(index+1,nums,target,curr_sum-nums[index]);

        return add_one + sub_one;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find_ways(0,nums,target,0);
    }
};