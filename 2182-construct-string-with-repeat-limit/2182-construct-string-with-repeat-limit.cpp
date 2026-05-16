class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto it : mpp){
            pq.push({it.first,it.second});
        }
        string ans="";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            char a1 = it.first;
            int freq=it.second;
            if(freq<=repeatLimit){
                ans+=string(freq,a1);
            }
            else{
                ans+=string(repeatLimit,a1);
                if(pq.empty()){
                    break;
                }
                auto sec = pq.top();
                pq.pop();
                char a2= sec.first;
                int freq2= sec.second;
                ans+=a2;
                pq.push({a1,freq-repeatLimit});
                if(freq2>1){
                    pq.push({a2,freq2-1});
                }
            }
        }
        return ans;
    }
};