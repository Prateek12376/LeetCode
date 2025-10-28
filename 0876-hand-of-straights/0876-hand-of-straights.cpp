class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>num_freq;
        for(int i=0;i<hand.size();i++){
            num_freq[hand[i]]++;
        }
        if(hand.size()%groupSize!=0){
            return false;
        }
        for(auto it : num_freq){
            int start=it.first;
            int freq=it.second;
            if(freq>0){
                while(freq>0){
                    for(int i=start;i<start+groupSize;i++){
                        if(num_freq[i]==0){
                            return false;
                        }
                        num_freq[i]--;
                    }
                    freq--;
                }
            }
        }
        return true;

    }
};