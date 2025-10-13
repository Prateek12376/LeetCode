class Solution {
public:
    bool is_not_Angram(string s, string q){
        if(s.size()!=q.size()){
            return true;
        }
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
            char c= s[i];
            arr[c-'a']++;
        }
        for(int i=0;i<q.size();i++){
            char s = q[i];
            arr[s-'a']--;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                return true;
            }
        }
        return false;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>result;
        result.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(is_not_Angram(words[i],words[i-1])){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};