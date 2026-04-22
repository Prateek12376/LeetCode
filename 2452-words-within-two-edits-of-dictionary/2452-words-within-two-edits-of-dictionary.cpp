class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n= queries.size();
        vector<int>vis(n,0);
        for (auto it : dictionary){
            string word = it;
            for(int i=0;i<queries.size();i++){
                string search = queries[i];
                int count=0;
                for(int i=0;i<search.size();i++){
                    if(word[i]!=search[i]){
                        count++;
                    }
                }
                if(count<3){
                    vis[i]=1;
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                ans.push_back(queries[i]);
            }
        }
        return ans;
    }
};