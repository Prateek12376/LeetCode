class Solution {
public:
    int binaryGap(int n) {
        vector<int>arr;
        while(n>0){
           arr.push_back(n % 2);
           n = n / 2;
        }
        reverse(arr.begin(),arr.end());
        int maxC=0;
        int start=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                if(start!=-1){
                    maxC=max(maxC, i-start);
                }
                start=i;
            }
        }
        return maxC;
    }
};