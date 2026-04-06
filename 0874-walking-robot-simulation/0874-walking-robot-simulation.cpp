class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(int i=0;i<obstacles.size();i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }
        int x=0;
        int y=0;
        int maxi=0;
        int dir=0;
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                dir= (dir+1)%4;  // right turn
            }
            else if(commands[i]==-2){
                dir=(dir+3)%4;  //left turn
            }
            else{
                for(int dist=1;dist<=commands[i];dist++){
                    int nx= x+dx[dir];
                    int ny= y+dy[dir];

                    if(st.count({nx,ny})){
                        break;
                    }
                    x=nx;
                    y=ny;
                    maxi=max(maxi,x*x+y*y);
                }
            }
        }
        return maxi;
    }
};