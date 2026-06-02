class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>targ;
        int size=p.size();
        for(int i=0;i<p.size();i++){
            targ[p[i]]++;
        }
        unordered_map<char,int>mpp;
        int ind=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;

            if(i-ind+1> p.size()){
                mpp[s[ind]]--;
                if(mpp[s[ind]]==0){
                    mpp.erase(s[ind]);
                }
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