class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int cnt=0;

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                cnt++;
            }
        }

        while(cnt>0){
            ans.push_back(pivot);
            cnt--;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};