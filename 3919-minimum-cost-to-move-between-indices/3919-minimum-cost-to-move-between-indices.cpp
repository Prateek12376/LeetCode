class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ans;
        vector<int>closeArr(n);
        for(int i=0;i<n;i++){
            if(i==0){
                closeArr[i]=1;
            }
            else if(i==n-1){
                closeArr[i]=n-2;
            }
            else{
                int left=abs(nums[i]-nums[i-1]);
                int right=abs(nums[i]-nums[i+1]);
                if(left<=right){
                    closeArr[i]=i-1;
                }
                else{
                    closeArr[i]=i+1;
                }
            }
        }

        vector<int>LC(n,0);
        vector<int>RC(n,0);
        LC[0]=0;
        RC[n-1]=0;
        for(int i=1;i<n;i++){
            if(closeArr[i-1]==i){
                LC[i]=1+ LC[i-1];
            }
            else{
                 LC[i]= LC[i-1]+ abs(nums[i]-nums[i-1]);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(closeArr[i+1]==i){
                RC[i]=1+RC[i+1];
            }
            else{
                RC[i]=RC[i+1] + abs(nums[i]-nums[i+1]);
            }
        }
        for(auto it : queries){
            int start=it[0];
            int end=it[1];
            if(start>end){
                ans.push_back(abs(RC[start]-RC[end]));
            }
            else{
                ans.push_back(abs(LC[end]-LC[start]));
            }
        }
        return ans;
    }
};