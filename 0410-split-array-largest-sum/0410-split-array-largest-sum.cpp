class Solution {
public:
    int find_sub_array(vector<int>& nums, int max_sum){
        int sum_array=0;
        int sub_array=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((sum_array+nums[i])<=max_sum){
                sum_array+=nums[i];
            }
            else{
                sub_array++;
                sum_array=nums[i];
            }
        }
        return sub_array;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int low=maxi;
        int high=sum;
        int ans = 0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int no_of_sub_array = find_sub_array(nums,mid);
            if(no_of_sub_array>k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};