class Solution {
public:
    void find_comb(int index,int size, int target,vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans){
        if(arr.size()==size){
            if(target==0){
                ans.push_back(arr);
            }
            return ;
        }
        if(index>=nums.size()){
            return ;
        }
        arr.push_back(nums[index]);
        find_comb(index+1,size,target-nums[index],nums,arr,ans);
        arr.pop_back();
        find_comb(index+1,size,target,nums,arr,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<10;i++){
            nums.push_back(i);
        }
        vector<int>arr;
        find_comb(0,k,n,nums,arr,ans);
        return ans;

    }

};