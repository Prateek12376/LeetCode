class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>freq1(10,0);
        vector<int>freq2(10,0);
        for(int i=0;i<secret.size();i++){
            freq1[secret[i]-'0']++;
            freq2[guess[i]-'0']++;
        }
        int bull=0;
        int cow=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                int num=secret[i]-'0';
                bull++;
                freq1[num]--;
                freq2[num]--;
            }
        }
        for(int i=0;i<10;i++){
            cow+=min(freq1[i],freq2[i]);
        }
        string ans="";
        ans+=to_string(bull);
        ans+="A";
        ans+=to_string(cow);
        ans+="B";
        return ans;
    }
};