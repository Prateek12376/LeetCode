class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1){
            return "";
        }
        string s= palindrome;
        int n=s.size();
        int i=0;
        int j=n-1;
        bool flg=false;
        while(i<j){
            if(s[i]!='a'){
                s[i]='a';
                flg=true;
                break;
            }
            i++;
            j--;
        }
        if(flg==false){
            s[n-1]='b';
        }
        return s;

    }
};