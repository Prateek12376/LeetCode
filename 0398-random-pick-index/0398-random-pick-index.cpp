class Solution {
public:
    unordered_map<int,vector<int>>mpp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>arr= mpp[target];
        int n=arr.size();
        int ind = rand()%n;
        return arr[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */