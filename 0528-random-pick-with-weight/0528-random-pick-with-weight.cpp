class Solution {
public:
    vector<int>ans;
    int sum=0;
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            ans.push_back(sum);
        }
    }
    
    int pickIndex() {
        int ind =rand()%sum +1;
        int res = lower_bound(ans.begin(),ans.end(),ind)-ans.begin();
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */