class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mpp;

        for(int i=0;i<26;i++){
            mpp[i]='z'-i;
        }

        string ans="";

        for(int i=0;i<words.size();i++){
            string word = words[i];
            int sum=0;
            for(int i=0;i<word.size();i++){
                sum+=(weights[word[i]-'a']);
            }
            int need =  sum%26;

            char ch  = mpp[need];
            ans+=ch;
        }
        return ans;
    }
};