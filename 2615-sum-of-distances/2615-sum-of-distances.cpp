class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        
        for(auto it: mpp){
            vector<int>& ans = it.second;
            int sz=ans.size();
            vector<long long>prefixSI(sz,0);
            prefixSI[0]=ans[0];
            for(int j=1;j<sz;j++){
                prefixSI[j]=prefixSI[j-1]+ans[j];
            }
            for(int k=0;k<sz;k++){
                long long left=0;
                long long right=0;
                if(k>0){
                    left= (long long)ans[k]*k - prefixSI[k-1];
                }
                if(k<sz-1){
                    right= (prefixSI[sz-1]-prefixSI[k])-(long long)ans[k]*(sz-1-k);
                }
                arr[ans[k]]=left+right;
            }
        }
        return arr;
    }
};