class Solution {
public:
    void find_comb(int index,vector<int>& arr,vector<vector<int>>& ans,int k,vector<int>& nums){
        if(index>=nums.size()){
            if(arr.size()==k){
            ans.push_back(arr);
            }
            return;
        }
        arr.push_back(nums[index]);
        find_comb(index+1,arr,ans,k,nums);
        arr.pop_back();
        find_comb(index+1,arr,ans,k,nums);

        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        find_comb(0,arr,ans,k,nums);
        return ans;
    }
};