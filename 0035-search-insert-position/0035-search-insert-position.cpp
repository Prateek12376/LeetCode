class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        return low;
    }
};