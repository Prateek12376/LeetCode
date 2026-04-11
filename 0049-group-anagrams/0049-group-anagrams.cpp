class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string c = strs[i];
            string  b = c;
            sort(c.begin(),c.end());
            mp[c].push_back(b);
        }
        vector<vector<string>>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};