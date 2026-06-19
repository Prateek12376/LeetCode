class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int alti;
        int maxi=0;
        int prev=0;
        for(int i=0;i<n;i++){
            alti=gain[i]+prev;
            maxi=max(maxi,alti);
            prev=alti;
        }
        return maxi;
    }
};