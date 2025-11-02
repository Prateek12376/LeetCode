class Solution {
public:
    void find_Guard(vector<vector<int>>& guards, vector<vector<int>>& box){
        vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<guards.size();i++){
            int r=guards[i][0];
            int c=guards[i][1];
            for(auto d: direction){
                int row= d[0]+r;
                int col=d[1]+c;
                while(row<box.size() && row>=0 && col>=0 && col<box[0].size()){
                    if(box[row][col]==1 || box[row][col]==2){
                        break;
                    }
                    if(box[row][col]==0){
                        box[row][col]=3;
                    }
                    row+=d[0];
                    col+=d[1];
                } 
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>box(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            box[guards[i][0]][guards[i][1]]=1;
        }
        for(auto w: walls){
            box[w[0]][w[1]]=2;
        }
        find_Guard(guards,box);

        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(box[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};