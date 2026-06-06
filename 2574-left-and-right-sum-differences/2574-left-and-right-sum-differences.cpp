class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return {0};
        }
        vector<int>leftS(n);
        vector<int>rightS(n);
        vector<int>ans(n);
        leftS[0]=nums[0];
        for(int i=1;i<n;i++){
            leftS[i]=nums[i]+leftS[i-1];
        }
        rightS[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightS[i]=nums[i]+rightS[i+1];
        }
        ans[0]=rightS[1];
        ans[n-1]=leftS[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=abs(leftS[i-1]-rightS[i+1]);
        }
        return ans;

    }
};