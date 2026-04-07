class Robot {
public:
    int n;
    int m;
    int dir=0;
    int x=0;
    int y=0;
    vector<string>dire={"East","North","West","South"};
    vector<pair<int,int>>d={{1,0},{0,1},{-1,0},{0,-1}};
    Robot(int width, int height) {
        n=height;
        m=width;
    }
    
    void step(int num) {
        int perimeter = 2*(n+m)-4;
        num=num%perimeter;
         if(num == 0){
            num = perimeter;
         }

        for(int i=1;i<=num;i++){
            int nx=x+d[dir].first;
            int ny=y+d[dir].second;
            if(nx>=m || nx<0 || ny>=n || ny<0){
                dir=(dir+1)%4;
                nx=x+d[dir].first;
                ny=y+d[dir].second;
            }
            x=nx;
            y=ny;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dire[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */