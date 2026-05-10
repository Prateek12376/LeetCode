class Solution {
public:
    bool isLower(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string ans="";
        for(int i=0;i<chunks.size();i++){
            ans+=chunks[i];
        }
        unordered_map<string,int>mpp;
        for(int i=0;i<ans.size();i++){
            while(i < ans.size() && (ans[i] == ' ' || ans[i] == '-')){
                i++;
            }
            int k=i;
            while(k<ans.size()){
                if(isLower(ans[k])==true){
                    k++;
                }
                else if(ans[k]=='-' && k-1>=0 && k+1<ans.size() && isLower(ans[k-1])==true && isLower(ans[k+1])==true){
                    k++;
                }
                else{
                    break;
                }
            }
            string part= ans.substr(i,k-i);
                mpp[part]++;
            i=k-1;
        }
        int n=queries.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(mpp[queries[i]]);
        }
        
        return res;
    }
};