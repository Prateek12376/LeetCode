class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<long long, int>row, col, dia1, dia2;
        set<pair<int,int>>st;

        for(auto it : lamps){
            int r= it[0];
            int c=it[1];
            if(st.count({r,c})){
                continue;
            }
            st.insert({r,c});
            row[r]++;
            col[c]++;
            dia1[r+c]++;
            dia2[r-c]++;
        }
        vector<int>ans;
        vector<pair<int,int>>dir={{0,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

        for(auto it : queries){
            int r=it[0];
            int c=it[1];
            if(row[r] || col[c] || dia1[r+c] || dia2[r-c] ){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
            for(auto d : dir){
                int nr= d.first+r;
                int nc=d.second+c;
                if(st.count({nr,nc})){
                    st.erase({nr,nc});
                    row[nr]--;
                    col[nc]--;
                    dia1[nr+nc]--;
                    dia2[nr-nc]--;
                }
            }
        }
        return ans;
    }
};