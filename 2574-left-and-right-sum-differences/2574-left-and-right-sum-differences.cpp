class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return {0};
        }
        int Tsum=0;
        for(int i=0;i<n;i++){
            Tsum+=nums[i];
        }
        vector<int>ans(n);

        int leftS=0;
        for(int i=0;i<n;i++){
            Tsum-=nums[i];
            int rightS= Tsum;

            ans[i]=abs(leftS-rightS);
            leftS+= nums[i];
        }
        return ans;

    }
};