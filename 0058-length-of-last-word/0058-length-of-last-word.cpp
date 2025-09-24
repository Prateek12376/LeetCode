class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int l=n-1;
        while(l>=0 && s[l]==' '){
            l--;
        }
        int count=0;
        while(l>=0 && s[l]!=' '){
            count++;
            l--;
        }
        return count;
    }
};