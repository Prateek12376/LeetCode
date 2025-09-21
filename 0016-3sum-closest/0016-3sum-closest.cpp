class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closest_sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int curr_sum= nums[i]+nums[l]+nums[r];
                if(abs(curr_sum-target)< abs(closest_sum-target)){
                    closest_sum=curr_sum;
                }
                else if(curr_sum==target){
                    return curr_sum;
                }
                else if(curr_sum<target){
                    l++;
                }
                else{
                    r--;
                }

            }
        }
        return closest_sum;
    }
};