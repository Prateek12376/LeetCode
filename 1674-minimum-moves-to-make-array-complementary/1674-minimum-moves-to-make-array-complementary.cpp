class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>diff(2*limit+2,0);
        int n=nums.size();
        for(int i=0;i<nums.size()/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int minS= 1+min(a,b);
            int maxS=limit+max(a,b);

            // add 2moves 
            diff[2]+=2;
            diff[2*limit+1]-=2;

            // for one move 

            diff[minS]+=(-1);
            diff[maxS+1]-=(-1);

            // for zero move
            diff[a+b]+=(-1);
            diff[a+b+1]-=(-1);
        }
        int result=INT_MAX;
        int curr=0;
        for(int i=2;i<2*limit+1;i++){
            curr+=diff[i];
            result=min(result,curr);
        }
        return result;
    }
};