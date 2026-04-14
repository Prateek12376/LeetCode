class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mpp;
        for(auto it : answers){
            mpp[it]++;
        }
        int count=0;
        for(auto it: mpp){
            int num= it.first;
            int freq=it.second;
            int n = freq/(num+1);
            count+=(1+num)*n;
            int extra = freq%(num+1);
            if(extra>0){
                count+=(1+num);
            }
        }
        return count ;
    }
};