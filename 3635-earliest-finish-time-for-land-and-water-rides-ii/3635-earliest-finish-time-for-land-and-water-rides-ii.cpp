class Solution {
public:
    int find_min_time(vector<int>& A1start , vector<int>& A1duration, vector<int>A2start, vector<int>A2duration){
        int mini=INT_MAX;
        for(int i=0;i<A1start.size();i++){
            int time = A1start[i] + A1duration[i];
            mini=min(mini,time);
        }
        int finishT = INT_MAX;
        for(int i=0;i<A2start.size();i++){
            int Time  = max(mini,A2start[i])+A2duration[i];
            finishT=min(finishT,Time);
        }
        return finishT;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int landF = find_min_time(landStartTime,landDuration,waterStartTime,waterDuration);
        int waterF = find_min_time(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(landF,waterF);
        
    }
};