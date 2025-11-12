class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
        }
        if(count>0){
            return n-count;
        }
        int op=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            int coun=0;
            for(int j=i;j<nums.size();j++){
                g=gcd(g,nums[j]);
                coun++;
                if(g==1){
                    op=min(op,coun);
                }
            }
        }
        if(op==INT_MAX){
            return -1;
        }
        int ans=0;
        ans=op+n-2;
        return  ans;
    }
};