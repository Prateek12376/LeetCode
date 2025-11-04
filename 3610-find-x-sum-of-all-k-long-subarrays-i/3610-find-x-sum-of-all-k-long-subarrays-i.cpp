struct doubles{
    int freq;
    int value;
    doubles(int f, int v){
        freq=f;
        value=v;
    }
};
static bool compare(doubles a, doubles b){
    if(a.freq==b.freq){
        return a.value>b.value;
    }
    return a.freq>b.freq;
}
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int i=0;
        while(i+k<=nums.size()){
            map<int,int>freq;
            vector<doubles>arr;
            for(int j=i; j<k+i;j++){
                freq[nums[j]]++;
            }
            for(auto it: freq){
                arr.push_back(doubles(it.second,it.first));
            }
            sort(arr.begin(),arr.end(),compare);
            int lim=x;
            int sum=0;
            int j=0;
            while(lim>0 && j<arr.size()){
                auto it= arr[j];
                sum+=it.freq*it.value;
                lim--;
                j++;
            }
            ans.push_back(sum);

            i++;
        }
        return ans;
        
    }
};