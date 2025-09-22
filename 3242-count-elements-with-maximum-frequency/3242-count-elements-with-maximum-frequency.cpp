class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        int maxFreq=0;
        int freq=0;
        for(auto it: map1){
            if(it.second> maxFreq){
                maxFreq= it.second;
                freq=it.second;
            }
            else if(it.second == maxFreq){
                freq+=it.second;
            }
            else{}
        }
        return freq;
    }
};