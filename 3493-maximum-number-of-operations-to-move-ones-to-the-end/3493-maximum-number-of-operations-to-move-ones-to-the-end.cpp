class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int ans=0;
        int count_1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count_1++;
            }
            else{
                if(i>0 && s[i-1]=='1'){
                    ans+=count_1;
                }
            }
        }
        return ans;

    }
    
};