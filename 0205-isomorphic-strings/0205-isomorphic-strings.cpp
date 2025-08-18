class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(int i=0;i<s.size();i++){
            char s1 = s[i];
            char t1 = t[i];
            if(map1.count(s1)&& map1[s1]!=t1){
                return false;
            }
            if(map2.count(t1) && map2[t1]!=s1){
                return false;
            }
            map1[s1]=t1;
            map2[t1]=s1;
        }
        return true;
    }
};