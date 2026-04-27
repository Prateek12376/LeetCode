class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int cnt=1;
        int val=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=val){
                continue;
            }
            else{
                val=points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};