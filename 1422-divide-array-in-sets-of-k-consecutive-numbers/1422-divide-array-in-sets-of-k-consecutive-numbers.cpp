class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>map1;
        for(auto it: nums){
            map1[it]++;
        }
        if(nums.size()%k!=0){
            return false;
        }

        for(auto it : map1){
            if(it.second>0){
                int freq=it.second;
                while(freq>0){
                    for(int i=it.first;i<it.first+k;i++){
                        if(map1[i]==0){
                            return false;
                        }
                        map1[i]--;
                    }
                    freq--;
                }
            }
        }
        return true;
    }
};