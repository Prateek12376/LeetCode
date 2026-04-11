class Solution {
public:
    bool isBalance(int i, int j, vector<int>& freq){
        int prev=-1;
        for(int k=0;k<26;k++){
            if(freq[k]!=0){
                if(prev!=-1 && freq[k]!=prev){
                    return false;

                }
                prev=freq[k];
            }
        }
        return true;
    }
    int find_minC(int i, int n, string& s, vector<int>& dpp){
        if(i==n){
            return 0;
        }
        if(dpp[i]!=-1){
            return dpp[i];
        }
        int minC = INT_MAX;
        vector<int>freq(26,0);
        for(int j=i;j<n;j++){
            freq[s[j]-'a']++;
            if(isBalance(i,j,freq)){
                int cut = 1 + find_minC(j+1,n,s,dpp);
                minC=min(minC,cut);
            }
        }
        return dpp[i]=minC;

    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int>dpp(n,-1);
        return find_minC(0,n,s,dpp);
    }
};