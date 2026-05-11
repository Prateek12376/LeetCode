class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            while(num>0){
                int n1=num%10;
                ans.push_back(n1);
                num=num/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};