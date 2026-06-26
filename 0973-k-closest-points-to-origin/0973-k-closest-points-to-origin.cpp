class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        for(auto it : points){
            int x= it[0];
            int y= it[1];

            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            auto it = pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};