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
            if(prefM[i]>suffMin){   // once we enter the suffMin region , then in the end we can reach the max elm 
                if(i+1<n){          // we can jump forward , if saller present after 
                    ans[i]=ans[i+1];
                }
                else{
                    ans[i]=prefM[i];
                }
            }
            else{                // other wise conider max till that elm
                ans[i]=prefM[i];
            }
            suffMin=min(suffMin,nums[i]);
        }
        return ans;
    }
};