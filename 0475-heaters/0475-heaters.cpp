class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int maxi=INT_MIN;
        for(int i=0;i<houses.size();i++){
            int ind = lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();

            int rightS=INT_MAX;
            int leftS=INT_MAX;

            if(ind<heaters.size()){
                rightS = heaters[ind]-houses[i];
            }
            if(ind>0){
                leftS= houses[i]- heaters[ind-1];
            }
            int dist = min(leftS,rightS);

            maxi=max(maxi,dist);
        }
        return maxi;

    }
};