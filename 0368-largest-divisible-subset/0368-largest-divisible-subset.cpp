class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        vector<int>dpp(n,1);
        vector<int>hash(n);
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int maxi=0;
        int startI=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0){
                    if(1+dpp[prev]>dpp[i]){
                        dpp[i]=1+dpp[prev];
                        hash[i]=prev;
                    }
                }
            }
            if(dpp[i]>maxi){
                startI=i;
                maxi=dpp[i];
            }
        }
        int i=startI;
        while(hash[i]!=i){
            ans.push_back(nums[i]);
            i=hash[i];
        }
        ans.push_back(nums[i]);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};