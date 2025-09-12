class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'|| c=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    bool doesAliceWin(string s) {
        int n= s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        if(count==0){
            return false;
        }
        else{
            return true;
        }
    }
};