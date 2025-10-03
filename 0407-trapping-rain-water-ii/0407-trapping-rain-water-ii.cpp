class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row= heightMap.size();
        int col= heightMap[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;

        int Twater=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || i==row-1 || j==0 || j==col-1){
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }


        while(!pq.empty()){
            int currHeight=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            vector<pair<int,int>>directions={{0,1},{0,-1},{-1,0},{1,0}};

            for(auto [dr,dc] : directions){
                int rr= r+dr;
                int cc=c+dc;
                if(rr>=0 && rr<row && cc>=0 && cc<col && !visited[rr][cc]){
                    pq.push({max(heightMap[rr][cc],currHeight),{rr,cc}});
                    visited[rr][cc]=true;
                    if(heightMap[rr][cc]<currHeight){
                        Twater+= currHeight - heightMap[rr][cc];
                    }
                }
            }
        }
        return Twater;
        
    }
}; 