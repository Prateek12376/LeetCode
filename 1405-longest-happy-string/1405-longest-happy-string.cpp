class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans="";
        while(pq.size()>1){
            auto it = pq.top();
            pq.pop();
            int f1=min(2,it.first);
            if(ans.empty() ||ans.back()!=it.second){
                ans+=string(f1,it.second);
                it.first=it.first-f1;
            }
            auto it2 = pq.top();
            pq.pop();
            int f2= min(1,it2.first);
            if(ans.empty() ||ans.back()!=it2.second){
                ans+=string(f2,it2.second);
                it2.first=it2.first-f2;
            }
            if(it.first>0){
                pq.push(it);
            }
            if(it2.first>0){
                pq.push(it2);
            }
        }
        if(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int f = min(2,it.first);
            int n=ans.size();
            if(ans.empty() ||(ans[n-1]!=it.second)|| (ans[n-1]==it.second && ans[n-2]!=it.second)){
                ans+=string(f,it.second);
            }
        }
        return ans;
    }
};