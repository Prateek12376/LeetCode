class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=0;
        for(int i=1;i<colors.size();i++){
            if(colors[0]!=colors[i]){
                maxi=max(maxi,abs(0-i));
            }
        }
        int n=colors.size();
        for(int j=n-2;j>=0;j--){
            if(colors[n-1]!=colors[j]){
                maxi=max(maxi,abs(n-1-j));
            }
        }
        return maxi;
    }
};