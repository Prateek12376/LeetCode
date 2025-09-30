class Solution {
public:
    void find_comb(int index, vector<int>& nums, vector<int>& arr, vector<int>& ans){
        int n= nums.size();
        if(index==n){
            int xor1=0;
            for(int i=0;i<arr.size();i++){
                xor1=xor1^arr[i];
            }
            ans.push_back(xor1);
            return;
        }
        arr.push_back(nums[index]);
        find_comb(index+1,nums,arr,ans);
        arr.pop_back();
        find_comb(index+1,nums,arr,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        vector<int>ans;
        vector<int>arr;
        find_comb(0,nums,arr,ans);
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        return sum;
    }
};