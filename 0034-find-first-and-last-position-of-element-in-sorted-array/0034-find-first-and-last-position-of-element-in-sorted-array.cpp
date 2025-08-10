class Solution {
public:
    int firstO(vector<int>& nums ,int target,int n){
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }return first;
    }
    int lastO(vector<int>& nums ,int target,int n){
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first = firstO(nums,target,n);
        if(first==-1){
            return {-1,-1};
        }
        int last = lastO(nums,target,n);
        return {first,last};
    }
};