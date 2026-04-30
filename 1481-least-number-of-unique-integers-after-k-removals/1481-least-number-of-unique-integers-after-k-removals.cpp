class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        vector<int>ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(k>=ans[i]){
                count++;
                k-=ans[i];
            }
        }
        return ans.size()-count;
    }
};