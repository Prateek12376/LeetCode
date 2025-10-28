class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26,0);
        for(auto ch: tasks){
            freq[ch-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        int time=0;
        while(!pq.empty()){
            int gap= n+1;
            vector<int>remain;
            while(gap>0 && !pq.empty()){
                int max_freq= pq.top();
                pq.pop();
                if(max_freq>1){
                    remain.push_back(max_freq-1);
                }
                time++;
                gap--;
            }
            for(auto it : remain){
                pq.push(it);
            }
            if(pq.empty()){
                break;
            }
            time+=gap;
        }
        return time;
    }
};