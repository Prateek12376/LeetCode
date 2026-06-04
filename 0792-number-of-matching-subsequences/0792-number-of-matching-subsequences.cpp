class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>arr(26);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a'].push_back(i);
        }
        int count=0;

        for(int i=0;i<words.size();i++){
            string sent=words[i];
            int ind=-1;
            bool flg=true;
            for(int i=0;i<sent.size();i++){
                char c = sent[i];
                vector<int>& ans= arr[c-'a'];

                int indB = upper_bound(ans.begin(),ans.end(),ind)-ans.begin();
                if(indB==ans.size()){
                    flg=false;
                    break;
                }
                else{
                    ind = ans[indB];
                }
            }
            if(flg==true){
                count++;
            }
        }
        return count;
    }
};