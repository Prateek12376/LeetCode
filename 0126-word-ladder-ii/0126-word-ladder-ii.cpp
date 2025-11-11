class Solution {
public:
    vector<vector<string>>ans;
    unordered_map<string,int>mp;
    string b;
public: 
    void dfs(string word, vector<string>& seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mp[word];
        for(int i=0;i<word.size();i++){
            char org= word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push({beginWord});
        st.erase(beginWord);
        mp[beginWord]=0;

        while(!q.empty()){
            string word= q.front();
            int steps= mp[word];
            q.pop();
            if(word==endWord){
                break;
            }
            for(int i=0;i<word.size();i++){
            char org= word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push({word});
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=org;
            }
        }

        if(mp.find(endWord)!=mp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
        
    }
};