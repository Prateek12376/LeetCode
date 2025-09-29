class Solution {
public:
    void find_combination(int index,int target, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans){
        if(index==nums.size()){
            if(target==0){
                ans.push_back(arr);
            }
            return ;
        }
        if(nums[index]<=target){
            arr.push_back(nums[index]);
            find_combination(index,target-nums[index],nums,arr,ans);
            arr.pop_back();
        }
        find_combination(index+1,target,nums,arr,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        find_combination(0,target,candidates,arr,ans);
        return ans;

    }
};