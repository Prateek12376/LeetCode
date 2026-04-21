class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>res;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto it: mpp){
            int size=it.first;
            vector<int>& ans=it.second;
            int i=0;
            while(i<ans.size()){
                vector<int>arr;
                int s=size;
                while(s>0){
                    arr.push_back(ans[i]);
                    s--;
                    i++;
                }
                res.push_back(arr);
            }
        }
        return res;
    }
};