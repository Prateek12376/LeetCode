class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>1){
            auto fir=pq.top();
            pq.pop();
            auto sec = pq.top();
            pq.pop();
            ans+=fir.second;
            ans+=sec.second;
            fir.first--;
            sec.first--;
            if(fir.first>0){
                pq.push(fir);
            }
            if(sec.first>0){
                pq.push(sec);
            }
        }
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            char c= pq.top().second;
            ans+=c;
        }
        return ans;
    }
};