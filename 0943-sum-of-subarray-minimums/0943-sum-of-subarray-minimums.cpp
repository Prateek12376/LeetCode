class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n),right(n);
        long long mod= 1e9+7;
        stack<int>st;
        // find PSE
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]= i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        // for NSE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        // contribution
        long long result=0;
        for(int i=0;i<n;i++){
            result=(result+(1LL*right[i]*left[i]*arr[i])%mod)%mod;
        }
        return (int)result;
    }
};