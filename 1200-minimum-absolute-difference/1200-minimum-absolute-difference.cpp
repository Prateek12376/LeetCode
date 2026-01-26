class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        if(arr.size()<3){
            return{{arr[0],arr[1]}};
        }
        int min_dif=arr[arr.size()-1];
        for(int i=1;i<arr.size();i++){
            min_dif=min(min_dif,arr[i]-arr[i-1]);
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==min_dif){
                ans.push_back({arr[i-1],arr[i]});
            }
        }

        return ans;
    }
};