class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.push(nums[i]);
            while(st.size()>1){
                int a= st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int g= gcd(a,b);
                if(g==1){
                    st.push(b);
                    st.push(a);
                    break;
                }
                long long LCM = (1LL*a*b)/g;
                st.push((int)LCM);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};