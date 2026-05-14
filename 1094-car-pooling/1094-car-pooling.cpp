class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>dropArr(1001,0);
        for(int i=0;i<trips.size();i++){
            int cap=trips[i][0];
            int src=trips[i][1];
            int dest=trips[i][2];
            dropArr[src]+=cap;
            dropArr[dest]-=cap;
        }
        int curr=0;
        for(int i=0;i<1001;i++){
            curr+=dropArr[i];
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};