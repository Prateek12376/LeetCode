class Solution {
public:
    void computelps(vector<int>& lps , string& s){
        int n= s.size();
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];

                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n= s.size();
        vector<int>lps(n);
        computelps(lps,s);
        int len= lps[n-1];
        if(len==0){
            return "";
        }
        string ans = s.substr(0,len);
        return ans;

    }
};