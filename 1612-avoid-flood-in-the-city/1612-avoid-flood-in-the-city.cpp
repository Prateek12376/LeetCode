class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>full_lake;
        set<int>dry_lakes;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                dry_lakes.insert(i);
            }
            else{
                if(full_lake.find(rains[i])!=full_lake.end()){
                    auto it = dry_lakes.upper_bound(full_lake[rains[i]]);
                    if(it==dry_lakes.end()){
                        return {};
                    }
                    int dryDay= *it;
                    ans[dryDay]=rains[i];
                    dry_lakes.erase(it);
                }
                full_lake[rains[i]]=i;
                ans[i]=-1;
            }
        }
        for(int day:dry_lakes){
            ans[day]=1;
        }
        return ans;

    }
};