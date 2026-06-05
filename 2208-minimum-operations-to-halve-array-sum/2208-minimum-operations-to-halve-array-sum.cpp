class Solution {
public:
    int halveArray(vector<int>& nums) {
        double p=0.0;
        priority_queue<double>pq;

        for(int i=0;i<nums.size();i++){
            p+=(double)nums[i];
            pq.push((double)nums[i]);
        }
        double sum = p/2.0;
        int cnt=0;
        double reducedS=0.0;
        while(!pq.empty() && reducedS<sum){
            double it = pq.top();
            double num=it/2.0;
            pq.pop();
            reducedS+=num;
            pq.push(num);
            cnt++;
        }
        return cnt;
    }
};