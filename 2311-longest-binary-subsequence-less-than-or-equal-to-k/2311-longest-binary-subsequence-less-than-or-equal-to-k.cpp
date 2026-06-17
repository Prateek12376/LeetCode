class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zero=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero++;
            }
        }

        vector<long long>two(33);
        two[0]=1;
        for(int i=1;i<33;i++){
            two[i]= 2*two[i-1];
        }
        long long num=0;
        int cnt=0;
        int n=s.size();
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                int pos=n-i-1;
                if(pos>32){
                    break;
                }
                num+=two[n-i-1];

                if(num<=(long long)k){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        return zero+cnt;
    }
};