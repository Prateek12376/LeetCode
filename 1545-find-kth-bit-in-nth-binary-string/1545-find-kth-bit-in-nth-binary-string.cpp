class Solution {
public:
    string reverse_string(string prev){
        string ans="";
        for(int i=0;i<prev.size();i++){
            if(prev[i]=='1'){
                ans+="0";
            }
            else{
                ans+="1";
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    char findKthBit(int n, int k) {
        string prev="0";
        string curr="";
        int val=2;
        while(val<=n){
            curr= prev+"1" + reverse_string(prev);
            prev=curr;
            val++;
        }
        return prev[k-1];
    }

};