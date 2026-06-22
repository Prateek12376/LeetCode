class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        for(int i=0;i<text.size();i++){
            mpp[text[i]]++;
        }
        string s = "balloon";
        int cnt=0;
        bool f1=true;
        while(true){
            int i=0;
            while(i<s.size()){
                if(mpp.find(s[i])==mpp.end()){
                    f1=false;
                    break;
                }
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            if(f1==true){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};