class Solution {
public:
    void find_comb(int index,int target,vector<int>& nums,vector<int>& arr,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(arr);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]>target){
                break;
            }
            else{
                arr.push_back(nums[i]);
                find_comb(i+1,target-nums[i],nums,arr,ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>arr;
        vector<vector<int>>ans;
        find_comb(0,target,candidates,arr,ans);
        return ans;
    }
};