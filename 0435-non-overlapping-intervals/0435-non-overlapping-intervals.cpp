struct Data{
    int start;
    int end;
};
static bool comp(Data a, Data b){
    return a.end<b.end;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<Data>interval_arr(n);
        for(int i=0;i<n;i++){
            interval_arr[i]={intervals[i][0],intervals[i][1]};
        }
        sort(interval_arr.begin(),interval_arr.end(),comp);
        int count=1;
        int Last_endTime= interval_arr[0].end;
        for(int i=1;i<n;i++){
            if(interval_arr[i].start>=Last_endTime){
                count++;
                Last_endTime= interval_arr[i].end;
            }
        }
        int remove= n-count;
        return remove;
    }
};