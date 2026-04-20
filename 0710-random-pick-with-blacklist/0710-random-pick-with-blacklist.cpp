class Solution {
public:
    int size;
    unordered_map<int,int>mpp;
    Solution(int n, vector<int>& blacklist) {
        size=n-blacklist.size();
        set<int>st;
        for(int i=0;i<blacklist.size();i++){
            st.insert(blacklist[i]);
        }
        int num=n-1;  // last number 
        for(int i=0;i<blacklist.size();i++){
            if(blacklist[i]<size){
                while(st.count(num)){
                    num--;
                }
                mpp[blacklist[i]]=num;
                num--;
            }
        }
    }
    
    int pick() {
        int ind = rand()%size;
        if(mpp.find(ind)!=mpp.end()){
            return mpp[ind];
        }
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */