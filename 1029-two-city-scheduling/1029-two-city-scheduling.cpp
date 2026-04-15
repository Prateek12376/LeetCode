class Solution {
public:
    static bool comp(vector<int>&a , vector<int>& b){
        return (a[0]-a[1])<(b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int cost=0;
        sort(costs.begin(),costs.end(),comp);
        for(int i=0;i<n;i++){
            if(i<n/2){
                cost+=costs[i][0];
            }
            else{
                cost+=costs[i][1];
            }
        }
        return cost;
        
    }
};