class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>alti(n+1);
        int maxi=0;
        for(int i=1;i<=n;i++){
            alti[i]=gain[i-1]+alti[i-1];
            maxi=max(maxi,alti[i]);
        }
        return maxi;
    }
};