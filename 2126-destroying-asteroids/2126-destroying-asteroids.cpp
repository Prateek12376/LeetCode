class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        long long cost=mass;

        for(int i=0;i<asteroids.size();i++){
            if(cost<asteroids[i]){
                return false;
            }
            else{
                cost+=asteroids[i];
            }
        }
        return true;
    }
};