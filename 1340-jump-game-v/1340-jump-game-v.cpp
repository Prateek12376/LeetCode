class Solution {
public:
    int find_way(vector<int>& arr, vector<int>& dpp, int ind , int d){
        if(ind==arr.size() || ind<0){
            return 0;
        }
        if(dpp[ind]!=-1){
            return dpp[ind];
        }
        int maxi=1;
        for(int i=1;i<=d;i++){
            if((ind+i)<arr.size() && arr[ind]>arr[ind+i]){
                maxi=max(maxi,1+find_way(arr,dpp,ind+i,d));
            }
            else{
                break;
            }
        }
        for(int i=1;i<=d;i++){
            if((ind-i)>=0 && arr[ind]>arr[ind-i] ){
                maxi=max(maxi,1+find_way(arr,dpp,ind-i,d));
            }
            else{
                break;
            }
        }
        return dpp[ind]=maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();

        vector<int>dpp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,find_way(arr,dpp,i,d));
        }
        return ans;
    }
};