// struct Time{
//     int time;
//     int index;
//     time(int t,int i){
//         time=t;
//         index=i;
//     }
// };
// static bool compare(Time a, Time b){
//     return Time.time<Time.time;
// }
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // vector<Time>nums;
        int time=0;
        // sort(nums.begin(),nums.end());
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                time+=min(neededTime[i],neededTime[i-1]);
                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return time;
    }
};