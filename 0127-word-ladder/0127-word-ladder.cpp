class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.count(beginWord)){
            st.erase(beginWord);
        }
        while(!q.empty()){
            string word = q.front().first;
            int move= q.front().second;
            q.pop();
            if(word==endWord){
                return move;
            }
            for(int i=0;i<word.size();i++){
                char org= word[i];

                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,move+1});
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};