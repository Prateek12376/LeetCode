class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.rbegin(),worker.rend());
        vector<pair<int,int>>arr;
        for(int i=0;i<profit.size();i++){
            arr.push_back({profit[i],difficulty[i]});
        }
        sort(arr.rbegin(),arr.rend());
        if(worker[0]<arr[profit.size()-1].second){
            return 0;
        }
        int ind=0;
        long long  ans=0;
        for(int i=0;i<worker.size();i++){
            if(worker[i]>=arr[ind].second){
                ans+= 1LL*arr[ind].first;
            }   
            else{
                while(worker[i]<arr[ind].second && ind<profit.size()){
                    ind++;
                }
                if(ind==profit.size()){
                    break;
                }
                ans+=1LL*arr[ind].first;
            }
        }
        return (int)ans;
    }
};