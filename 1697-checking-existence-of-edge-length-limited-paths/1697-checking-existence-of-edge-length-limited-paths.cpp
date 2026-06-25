struct DSU{
public:
    vector<int>parent;
    vector<int>size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find_UP(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find_UP(parent[node]);
    }

    void join(int v, int u){
        int ultp_v = find_UP(v);
        int ultp_u = find_UP(u);

        if(ultp_v==ultp_u){
            return;
        }
        if(size[ultp_v]>size[ultp_u]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),[&](vector<int>a , vector<int>b){
            return a[2]<b[2];
        });
        sort(queries.begin(),queries.end(),[&](vector<int>a , vector<int>b){
            return a[2]<b[2];
        });
        int ind=0;
        int n1=queries.size();
        vector<bool>ans(n1);
        DSU dsu(n+1);
        for(int i=0;i<queries.size();i++){
            int tu = queries[i][0];
            int tv= queries[i][1];
            int tw = queries[i][2];
            int index = queries[i][3];

            while(ind<edgeList.size() && edgeList[ind][2]<tw){
                int u= edgeList[ind][0];
                int v= edgeList[ind][1];

                if(dsu.find_UP(u)!=dsu.find_UP(v)){
                    dsu.join(u,v);
                }
                ind++;
            }
            if(dsu.find_UP(tu)==dsu.find_UP(tv)){
                ans[index]=true;
            }
            else{
                ans[index]=false;
            }

        }
        return ans;
    }
};