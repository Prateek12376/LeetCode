class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string s1="";
            while(s[i]!=' ' && i<s.size()){
                s1+=s[i];
                i++;
            }
            reverse(s1.begin(),s1.end());
            ans+=s1;
            while(s[i]==' ' && i<s.size()){
                ans+=s[i];
                i++;
            }
            i--;
        }
        return ans;
    }
};