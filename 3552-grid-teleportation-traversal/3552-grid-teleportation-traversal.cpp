class Solution {
public:
    int minMoves(vector<string>& matrix) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        unordered_map<char,vector<pair<int,int>>>mpp;
        int n= matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]>='A' && matrix[i][j]<='Z'){
                    mpp[matrix[i][j]].push_back({i,j});
                }
            }
        }
        vector<int>tel(26,0);
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int r= it.second.first;
            int c = it.second.second;
            int move=it.first;
            if(vis[r][c]==1){
                continue;
            }
            vis[r][c]=1;

            if(r==n-1 && c==m-1){
                return move;
            }
            if(matrix[r][c]>='A' && matrix[r][c]<='Z' && tel[matrix[r][c]-'A']!=1){
                tel[matrix[r][c]-'A']=1;
                vector<pair<int,int>>& telp = mpp[matrix[r][c]];

                for(auto it : telp){
                    int nr = it.first;
                    int nc= it.second;
                    if(vis[nr][nc]!=1){
                        pq.push({move,{nr,nc}});
                    }
                }
            }
            for( auto it : dir){
                int nr= it.first+r;
                int nc = it.second+c;
                if(nr<n && nc<m && nr>=0 && nc>=0 && matrix[nr][nc]!='#' && vis[nr][nc]!=1){
                    pq.push({move+1,{nr,nc}});
                }
            }

        }
        return -1;

    }
};