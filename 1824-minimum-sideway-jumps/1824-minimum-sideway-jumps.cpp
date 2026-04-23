class Solution {
public:
    int minJ(int ind, vector<int>& obstacles , vector<vector<int>>& dpp,int lane){
        if(ind==obstacles.size()-1){
            return 0;
        }
        if(dpp[ind][lane]!=-1){
            return dpp[ind][lane];
        }
        if(obstacles[ind+1]!=lane){
            int mov= minJ(ind+1,obstacles,dpp,lane);
            return dpp[ind][lane]=mov;
        }
        else{
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(i!=lane && obstacles[ind]!=i){
                    int laneC  = 1+ minJ(ind,obstacles,dpp,i);
                    ans=min(ans,laneC);
                }
            }
            return dpp[ind][lane]=ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>>dpp(n,vector<int>(4,-1));
        return minJ(0,obstacles,dpp,2);
    }
};