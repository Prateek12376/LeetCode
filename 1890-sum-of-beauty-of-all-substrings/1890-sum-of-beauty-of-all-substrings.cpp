class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int b_string_sum=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                
                for(auto f:freq){
                    if(f>0){
                         maxi=max(maxi,f);
                        mini=min(mini,f);
                    }
                }
                b_string_sum+=(maxi-mini);
            }
        }
        return b_string_sum;
        
    }
};