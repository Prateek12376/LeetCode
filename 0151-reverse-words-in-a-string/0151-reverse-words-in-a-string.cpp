class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            string new_s="";
            while(i<n && s[i]!=' '){
                new_s+=s[i];
                i++;
            }
            reverse(new_s.begin(),new_s.end());
            if(new_s.length()>0){
                ans+=" "+new_s;
            }
        }
        return ans.substr(1);
    }
};