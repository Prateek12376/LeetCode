class Solution {
public:
    bool compare(string curr, string prev){
        int n=curr.size();
        int m=prev.size();
        if(n!=m+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<n){
            if(j<m && curr[i]==prev[j]){
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(j==m){
            return true;
        }
        else{
            return false;
        }
    }
    static bool comp(string& a, string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        vector<int>dpp(n,1);
        int maxi=0;
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[i],words[prev])==true){
                    if(1+dpp[prev]>dpp[i]){
                        dpp[i]=dpp[prev]+1;
                    }
                }
            }
            maxi=max(maxi,dpp[i]);
        }
        return maxi;
    }
};