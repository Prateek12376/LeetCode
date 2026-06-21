class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi=INT_MIN;
        for(int i=0;i<costs.size();i++){
            maxi=max(maxi,costs[i]);
        }
        vector<int>nums(maxi+1,0);

        for(int i=0;i<costs.size();i++){
            nums[costs[i]]++;
        }
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                while(nums[i]>0){
                    costs[ind]=i;
                    ind++;
                    nums[i]--;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<costs.size();i++){
            if((coins-costs[i])>=0){
                coins-=costs[i];
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};