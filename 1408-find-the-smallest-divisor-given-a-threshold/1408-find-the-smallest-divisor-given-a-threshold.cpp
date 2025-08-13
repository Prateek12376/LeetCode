class Solution {
public:
    int sum_after_divide_by_D(vector<int>& nums,int mid){
        int n=nums.size();
        int sum_after_Divide=0;
        for(int i=0;i<n;i++){
            sum_after_Divide += ceil((double)nums[i]/(double)mid);
        }
        return sum_after_Divide;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold){
            return -1;
        }
        int maxi=INT_MAX;
        for(int i=0;i<n;i++){
            maxi= max(maxi,nums[i]);
        }
        int  low=1;
        int high=maxi;
        int ans=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int possible_ans= sum_after_divide_by_D(nums,mid);
            if(possible_ans<=threshold){
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