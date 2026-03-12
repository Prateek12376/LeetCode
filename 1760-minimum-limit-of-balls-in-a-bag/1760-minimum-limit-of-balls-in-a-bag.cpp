class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=INT_MIN;
        for(int i=0;i<nums.size();i++){
            r=max(r,nums[i]);
        }
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            long long op=0;
            for(int i=0;i<nums.size();i++){
                op+= (nums[i]-1)/mid;
            }
            if(op<=maxOperations){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};