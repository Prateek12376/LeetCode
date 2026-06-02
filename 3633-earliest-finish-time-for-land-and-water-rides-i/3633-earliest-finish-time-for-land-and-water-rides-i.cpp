class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
       int ans = INT_MAX;

        // Land first
        for(int i = 0; i < landStartTime.size(); i++){
            int landFinish = landStartTime[i] + landDuration[i];

            for(int j = 0; j < waterStartTime.size(); j++){
                ans = min(ans,
                        max(landFinish, waterStartTime[j]) + waterDuration[j]);
            }
        }

        // Water first
        for(int i = 0; i < waterStartTime.size(); i++){
            int waterFinish = waterStartTime[i] + waterDuration[i];

            for(int j = 0; j < landStartTime.size(); j++){
                ans = min(ans,
                        max(waterFinish, landStartTime[j]) + landDuration[j]);
            }
        }

        return ans;


    }
};