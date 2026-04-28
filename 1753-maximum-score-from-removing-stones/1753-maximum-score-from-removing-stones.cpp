class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int score=0;
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            first--;
            second--;
            score++;
            if(first>0){
                pq.push(first);
            }
            if(second>0){
                pq.push(second);
            }
        }
        return score;
    }
};