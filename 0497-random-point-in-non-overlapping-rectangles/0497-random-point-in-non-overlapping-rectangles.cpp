class Solution {
public:
    vector<vector<int>> rects;
    vector<int>prefix;
    int sum=0;
    Solution(vector<vector<int>>& rects) {
        this->rects=rects;

        for(auto it : rects){
            int x1= it[0];
            int y1=it[1];
            int x2=it[2];
            int y2=it[3];
            sum+= (x2-x1+1)*(y2-y1+1);
            prefix.push_back(sum);

        }

    }
    
    vector<int> pick() {
        int randP = rand()% sum +1;
        int rectInd = lower_bound(prefix.begin(),prefix.end(),randP)-prefix.begin();

        vector<int>r = rects[rectInd];

        int x1= r[0];
        int y1=r[1];
        int x2= r[2];
        int y2=r[3];
        int x = x1 + rand()%(x2-x1+1);
        int y= y1+ rand()%(y2-y1+1);
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */