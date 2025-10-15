class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>e_length(n,1);// left to right
        vector<int>s_length(n,1); // right to left 
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                e_length[i]=e_length[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                s_length[i]= s_length[i+1]+1;
            }
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,min(e_length[i],s_length[i+1]));
        }
        return maxi;
    }
};