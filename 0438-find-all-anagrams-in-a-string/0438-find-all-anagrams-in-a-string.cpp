class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>targ(26,0);
        int size=p.size();
        for(int i=0;i<p.size();i++){
            targ[p[i]-'a']++;
        }
        vector<int>mpp(26,0);
        int ind=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            mpp[s[i]-'a']++;

            if(i-ind+1> p.size()){
                mpp[s[ind]-'a']--;
                ind++;
            }
            if(i-ind+1==p.size()){
                if(mpp==targ){
                    ans.push_back(ind);
                }
            }
        }
        return ans;
    }
};