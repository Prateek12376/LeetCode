class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        int op=0;
        st.push(0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
            }
            if(st.empty() || st.top()<nums[i]){
                op++;
                st.push(nums[i]);
            }
        }
        return op;
            
        
    }
};