class Solution {
public:
    int maxS(int i, int n, int k, vector<int>& arr, vector<int>& dpp){
        if(i==n){
            return 0;
        }
        if(dpp[i]!=-1){
            return dpp[i];
        }
        int maxiC = INT_MIN;
        int maxi=-1;
        for(int j=i;j<min(i+k,n);j++){
            maxi=max(maxi,arr[j]);

            int cost =maxi*(j-i+1) + maxS(j+1,n,k,arr,dpp);

            maxiC= max(maxiC,cost);
        }
        return dpp[i]=maxiC;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dpp(n,-1);
        return maxS(0,n,k,arr,dpp);


    }
};