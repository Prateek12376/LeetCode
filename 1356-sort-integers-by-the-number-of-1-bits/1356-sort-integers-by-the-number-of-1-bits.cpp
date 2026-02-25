class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>bit_index;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            int count=0;
            while(num>0){
                if(num%2!=0){
                    count++;
                }
                num=num/2;
            }
            bit_index.push_back({count,i});
        }
        sort(bit_index.begin(),bit_index.end());
        vector<int>result;
        for(auto it : bit_index){
            result.push_back(arr[it.second]);
        }
        return result;
    }
};