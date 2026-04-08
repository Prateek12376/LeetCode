class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,long long>mp;
        int n=rectangles.size();
        for(auto it: rectangles){
            int w =it[0];
            int h=it[1];
            double a= (double)h/w;
            mp[a]++;
        }
        long long ans=0;
        for(auto it : mp){
            long long option =it.second;
            ans+= option*(option-1)/2;

        }
        return ans;
    }
};