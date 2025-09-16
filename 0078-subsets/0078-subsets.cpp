class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        int no_sub_set=1<<n;
        for(int sub_set=0;sub_set<no_sub_set;sub_set++){
            vector<int>subset;
            for(int j=0;j<n;j++){
                if(((sub_set>>j)&1)!=0){
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;

    }
};