class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,pair<int,int>>mp;
        set<int>st;
        vector<int>ans;
        for(int a=1;a<=1000;a++){
            for(int b=a;b<=1000;b++){
                int sum= a*a*a + b*b*b;
                if(sum<=n){
                    if(mp.find(sum)!=mp.end()){
                        st.insert(sum);
                    }
                    mp[sum]={a,b};
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};