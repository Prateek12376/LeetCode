class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr){
        int n=arr.size();
        vector<int>left(n),right(n);
        stack<int>st;
        //pse
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //nse
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
        //contribution
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= (1LL*left[i]*right[i]*arr[i]);
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr){
        int n=arr.size();
        vector<int>left(n),right(n);
        stack<int>st;
        //PLE
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //NLE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
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
        //contribution
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= (1LL*left[i]*right[i]*arr[i]);
        }
        return sum;

    }
    long long subArrayRanges(vector<int>& nums) {
        long long result= sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
        return result;
    }
};