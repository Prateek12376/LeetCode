
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        
        sort(intervals.begin(),intervals.end(),[&](vector<int>a, vector<int>b){
            return a[1]<b[1];
        });
        vector<vector<int>>ans;
        int count=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<ans.back()[1]){
                count++;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return count;
    }
};