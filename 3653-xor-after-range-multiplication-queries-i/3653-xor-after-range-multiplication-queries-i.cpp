class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;

        for(auto it : queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int val= it[3];

            while(l<=r){
                nums[l]= (1LL*nums[l]*val)%mod;
                l+=k;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};