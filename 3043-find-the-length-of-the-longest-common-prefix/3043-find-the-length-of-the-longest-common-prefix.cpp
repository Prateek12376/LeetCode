class Solution {
public:
    int len(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n /= 10;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int>st;
        for(int i=0;i<arr1.size();i++){
            int n= arr1[i];
            while(n>0){
                st.insert(n);
                n=n/10;
            }
        }
        int maxi=0;
        for(int i=0;i<arr2.size();i++){
            int n1=arr2[i];
            while(n1>0){
                if(st.count(n1)){
                    int n= len(n1);
                    maxi=max(maxi,n);
                }
                n1=n1/10;
            }
        }
        return maxi;
    }
};