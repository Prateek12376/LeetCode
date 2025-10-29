class Twitter {
public:
    long long time;
    unordered_map<int,vector<pair<long long, int>>>tweet;
    unordered_map<int,set<int>>follow_map;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        follow_map[userId].insert(userId);
        priority_queue<pair<long long,int>>pq;

        for(auto followee : follow_map[userId]){
            if(tweet.find(followee)!=tweet.end()){
                for(int i=max(0,(int)tweet[followee].size()-10);i<(int)tweet[followee].size();i++){
                    pq.push(tweet[followee][i]);
                }
            }
        }
        vector<int>res;
        int max=10;
        while(!pq.empty() && max>0){
            auto it= pq.top();
            pq.pop();
            res.push_back(it.second);
            max--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        if(follow_map.find(followerId)!=follow_map.end()){
            follow_map[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */