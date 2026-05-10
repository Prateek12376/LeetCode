class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(2*n);
        for(int i=0;i<n;i++){
            result[i]=nums[i];
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            result[n+i]=nums[i];
        }
        return result;
    }
};