class DisjointSet{
  vector<int>parent,size;      
public:
  DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
  }
  int findUP(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findUP(parent[node]);
  }
  void UnionBySize(int u, int v){
    int ultp_u = findUP(u);
    int ultp_v= findUP(v);
    if(ultp_u==ultp_v){
        return;
    }
    if(size[ultp_u]<size[ultp_v]){  
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet Ds(n);
        unordered_map<string,int>mail_node;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail  = accounts[i][j];
                if(mail_node.find(mail)==mail_node.end()){
                    mail_node[mail]=i;
                }
                else{
                    Ds.UnionBySize(i,mail_node[mail]);
                }
            }
        }
        vector<vector<string>>merge_mail(n);

        for(auto it : mail_node){
            string mail = it.first;
            int node = Ds.findUP(it.second);
            merge_mail[node].push_back(mail);
        }
        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(merge_mail[i].size()==0){
                continue;
            }
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(merge_mail[i].begin(),merge_mail[i].end());
            for(auto it : merge_mail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};