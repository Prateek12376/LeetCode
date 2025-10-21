class Solution {
public:
    int find_lower(vector<int>& nums, int target){
        int low = 0, high = nums.size();
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target) high = mid;
            else low = mid+1;
        }
        return low;
    }
    int find_upper(vector<int>& nums, int target){
        int low = 0, high = nums.size();
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] > target) high = mid;
            else low = mid+1;
        }
        return low;
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        map<int,int>map1;
        for(int i=0;i<n;i++){
            map1[nums[i]]++;
        }
        for(int target=nums[0];target<=nums[n-1];target++){
            int left=find_lower(nums,target-k);
            int right=find_upper(nums,target+k);
            int total = right - left;
            int op = total - map1[target];
            int achieved = map1[target] + min(op, numOperations);
            ans = max(ans, achieved);
        }
        return ans;
        
    }
};