class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int val=pq.top();
            pq.pop();
            int newV= floor(val/2);
            newV+=val%2;
            pq.push(newV);
            k--;
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};