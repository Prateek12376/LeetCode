class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        int count=0;
        unordered_set<int>st;
        // sort(arr.begin(),arr.end());
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                if(st.count(arr[i])){
                    while(arr[i]>0 && st.count(arr[i])){
                        arr[i]--;
                        count++;
                    }
                }
                if(arr[i]!=0){
                    st.insert(arr[i]);
                }
            }
        }
        return count;
    }
};