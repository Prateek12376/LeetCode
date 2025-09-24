class Solution {
public:
    bool isVowel(char s){
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'|| s=='U'){
            return true;
        }
        else{
            return false;
        }
    }
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(isVowel(s[l]) ){
                if(isVowel(s[r])){
                    int temp=s[l];
                    s[l]=s[r];
                    s[r]=temp;
                    l++;
                    r--;
                }
                else{
                    while(!isVowel(s[r])){
                        r--;
                    }
                }
            }
            else{
                l++;
            }
        }
        return s;
    }
};