class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int b_string_sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>map1;
            for(int j=i;j<n;j++){
                map1[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                
                for(auto freq: map1){
                    maxi=max(maxi,freq.second);
                    mini=min(mini,freq.second);
                }
                b_string_sum+=(maxi-mini);
            }
        }
        return b_string_sum;
        
    }
};