class Solution {
public:
    bool isSubsequence(string s, string t) {
        int  l=0;
        int  r=0;
        int count=0;
        while(l<s.size() && r<t.size()){
            if(s[l]==t[r]){
                count++;
                l++;
            }
            r++;
        }
        if(count==s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};