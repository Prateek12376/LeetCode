class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int Tgas =0;
       int Tcost=0;
        for(int i=0;i<cost.size();i++){
            Tgas+=gas[i];
            Tcost+=cost[i];
        }
        if(Tgas<Tcost){
            return -1;
        }
        int StationC=0;
        int StationG=0;
        int start=0;
        for(int i=0;i<cost.size();i++){
            StationC+=cost[i];
            StationG+=gas[i];
            if(StationC>StationG){
                start=i+1;
                StationG=0;
                StationC=0;
            }
        }
        return start;
    }
};