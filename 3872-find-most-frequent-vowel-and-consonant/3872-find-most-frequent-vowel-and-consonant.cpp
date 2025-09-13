class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    int maxFreqSum(string s) {
        vector<int>arr(26);
        vector<int>arr2(26);
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                arr[s[i]-'a']++;
            }
            else{
                arr2[s[i]-'a']++;
            }
        }
        int maxi1= 0;
        int maxi2=0;
        for(int i=0;i<26;i++){
            maxi1=max(maxi1,arr[i]);
            maxi2=max(maxi2,arr2[i]);
        }
        return maxi1+maxi2;
    }
};