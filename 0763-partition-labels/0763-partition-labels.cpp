class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>>alpha(26,{-1,-1});

        for(int i=0;i<s.size();i++){
            // first index
            if(alpha[s[i]-'a'].first==-1){
                alpha[s[i]-'a'].first=i;
            }
            // last index;
            if(alpha[s[i]-'a'].second<i){
                alpha[s[i]-'a'].second=i;
            }
        }
        int i=0;
        vector<int>ans;
        while(i<s.size()){
            int fO  = alpha[s[i]-'a'].first;
            int lO = alpha[s[i]-'a'].second;
            while(i<=lO){
                if(alpha[s[i]-'a'].second>lO){
                    lO=alpha[s[i]-'a'].second;
                }
                i++;
            }
            ans.push_back(lO-fO+1);
        }
        return ans;
    }
};