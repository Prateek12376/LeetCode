class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int i=0;i<speed.size();i++){
            double val = (double)dist[i]/speed[i];
            pq.push(val);
        }
        int t=0;
        int count=0;
        while(!pq.empty()){
            double time = pq.top();
            pq.pop();
            
            if(time-t<=0){
                break;
            }
            t++;
            count++;
        }
        return count;
    }
};