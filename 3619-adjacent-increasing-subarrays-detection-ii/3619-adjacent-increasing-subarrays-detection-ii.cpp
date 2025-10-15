class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int prev=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            curr++;
            if(i==n-1 || nums[i]>=nums[i+1]){
                maxi= max({maxi,curr/2,min(prev,curr)});
                prev=curr;
                curr=0;
            }
        }
        return maxi;
    }
};