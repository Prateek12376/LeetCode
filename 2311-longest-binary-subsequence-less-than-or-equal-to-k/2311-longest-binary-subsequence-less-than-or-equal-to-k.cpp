class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero++;
            }
        }
        long long pow=1;
        long long num=0;
        int cnt=0;
        int n=s.size();
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){

                if((num+pow)<=(long long)k){
                    num+=pow;
                    cnt++;
                }
            }
            if(pow<=(long long)k){
                pow=pow<<1;
            }
            else{
                break;
            }
        }
        return zero+cnt;
    }
};