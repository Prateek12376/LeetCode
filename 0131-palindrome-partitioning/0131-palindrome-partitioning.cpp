class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void find_partition(int index, string s, vector<string>& validS,vector<vector<string>>& ans){
        if(index==s.size()){
            ans.push_back(validS);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                validS.push_back(s.substr(index,i-index+1));
                find_partition(i+1,s,validS,ans);
                validS.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>validS;
        find_partition(0,s,validS,ans);
        return ans;
    }
};