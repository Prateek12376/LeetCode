class Router {
public:
    queue<pair<int,pair<int,int>>>q;
    set<pair<int,pair<int,int>>>st;
    unordered_map<int,vector<int>>mpp;
    int size;
    Router(int memoryLimit) {
        size=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.count({timestamp,{destination,source}})){
            return false;
        }
        if(q.size()==size){
            auto it=q.front();
            int dest = it.second.first;
            int time = it.first;
            q.pop();
            st.erase(it);
            auto &v = mpp[dest];
            auto ind = lower_bound(v.begin(), v.end(), time);
            v.erase(ind);


        }
        st.insert({timestamp,{destination,source}});
        q.push({timestamp,{destination,source}});
        mpp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0){
            return {};
        }
        auto it = q.front();
        int dest = it.second.first;
        int time = it.first;
        auto &v = mpp[dest];
        auto ind  = lower_bound(v.begin(),v.end(),time);
        v.erase(ind);
        st.erase(it);
        q.pop();
        vector<int>ans;
        ans.push_back(it.second.second);
        ans.push_back(it.second.first);
        ans.push_back(it.first);
        return ans;

    }
    
    int getCount(int destination, int startTime, int endTime) {
        int count=0;
        if(mpp.find(destination)==mpp.end()){
            return count;
        }
        auto &s = mpp[destination];
        auto l = lower_bound(s.begin(),s.end(),startTime);
        auto r=  upper_bound(s.begin(),s.end(),endTime);
        return r-l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */