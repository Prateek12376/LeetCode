class Solution {
public:
    void computeLps(vector<int>& lps, string& s){
        int n=s.size();
        lps[0]=0;
        int i=1;
        int len=0;

        while(i<n){
            if(s[i]==s[len]){
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
    string shortestPalindrome(string s) {
        string rev= s;
        reverse(rev.begin(),rev.end());

        string temp=  s +"#" + rev; 
        int n=temp.size();
        vector<int>lps(n);
        computeLps(lps,temp);

        int len = lps[n-1];

        string add=  s.substr(len);

        reverse(add.begin(),add.end());
        return add+s;
        
    }
};