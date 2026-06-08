class Solution {
public:
    int find_n(vector<int>& nums, int maxS){
        int cntS =1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>maxS){
                sum=nums[i];
                cntS++;
            }
            else{
                sum+=nums[i];
            }
        }
        return cntS;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi= INT_MIN;
        int sum=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int ans=-1;
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid= low+ (high-low)/2;

            int nSubA = find_n(nums,mid);

            if(nSubA<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};