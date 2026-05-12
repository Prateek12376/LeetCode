class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>a, vector<int>b){
            if((a[1]-a[0])==(b[1]-b[0])){
                return a[1]>b[1];
            }
            return (a[1]-a[0])>(b[1]-b[0]);

        });
        int count=tasks[0][1];
        int rem= count-tasks[0][0];
        for(int i=1;i<tasks.size();i++){
            if(rem>=tasks[i][1]){
                rem-=tasks[i][0];
            }
            else{
                count+=tasks[i][1]-rem;
                rem=tasks[i][1]-tasks[i][0];
            }
        }
        return count;
    }
};