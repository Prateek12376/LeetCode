class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>lower;
        unordered_map<char,int>current;
        vector<int>vis(26,0);

        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                lower[word[i]]++;
            }
        }
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                current[word[i]]++;
            }
            else{
                char c= tolower(word[i]);
                if(lower[c] > 0 && lower[c]==current[c] && vis[c-'a']==0){
                    vis[c-'a']=1;
                }
                else if(vis[c-'a']==0){
                    vis[c-'a']=2;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(vis[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};