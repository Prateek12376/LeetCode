class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefM(n);
        prefM[0]=nums[0];
        int maxi=nums[0];

        for(int i=1;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefM[i]=maxi;
        }
        vector<int>sufmin(n);
        int suffMin=INT_MAX;
        int mini=nums[n-1];
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(prefM[i]>suffMin){
                if(i+1<n){
                    ans[i]=ans[i+1];
                }
                else{
                    ans[i]=prefM[i];
                }
            }
            else{
                ans[i]=prefM[i];
            }
            suffMin=min(suffMin,nums[i]);
        }
        return ans;
    }
};