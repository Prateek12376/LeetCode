class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxArea_R=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int nse=i;
                int elmI= st.top();
                st.pop();
                int pse;
                if(!st.empty()){
                    pse=st.top();
                }
                else{
                    pse=-1;
                }
                maxArea_R= max((heights[elmI]*(nse-pse-1)),maxArea_R);
            }
            st.push(i);
        }
        while(!st.empty()){
            int elmI=st.top();
            st.pop();
            int nse=n;
            int pse;
            if(!st.empty()){
                pse=st.top();
            }
            else{
                pse=-1;
            }
            maxArea_R= max((heights[elmI]*(nse-pse-1)),maxArea_R);
        }
        return maxArea_R;
    }
};