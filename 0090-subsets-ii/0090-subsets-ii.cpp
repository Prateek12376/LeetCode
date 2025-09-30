class Solution {
public:
    void find_comb(int index,vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans){
        ans.push_back(arr);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            else{
                arr.push_back(nums[i]);
                find_comb(i+1,nums,arr,ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        vector<vector<int>>ans;
        find_comb(0,nums,arr,ans);
        return ans;

    }
};