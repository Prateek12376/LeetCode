class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        vector<vector<long long>>dist(26,vector<long long>(26,LLONG_MAX));

        for(int i=0;i<original.size();i++){
            int u= original[i]-'a';
            int v= changed[i]-'a';
            long long wt = 1LL* cost[i];
            dist[u][v]=min(dist[u][v],wt);
        }
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(dist[i][k]<LLONG_MAX && dist[k][j]<LLONG_MAX){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
            }
        }
        long long min_cost=0;
        for(int i=0;i<source.size();i++){
            int from = source[i]-'a';
            int to= target[i]-'a';
            if(dist[from][to]==LLONG_MAX){
            return -1;
            }
            min_cost+=dist[from][to];
        }
        return min_cost;
    }
};