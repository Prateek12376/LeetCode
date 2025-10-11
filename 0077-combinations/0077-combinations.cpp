class Solution {
public:
    void find_comb(int index,vector<int>& arr,vector<vector<int>>& ans,int k,int n){
        if(arr.size()==k){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<=n;i++){
            arr.push_back(i);
            find_comb(i+1,arr,ans,k,n);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<vector<int>>ans;
        find_comb(1,arr,ans,k,n);
        return ans;
    }
};