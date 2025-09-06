class Solution {
public:
    int largestRectangleArea_by_pSum_row(vector<int>& arr){
        int n=arr.size();
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int elmI=st.top();
                st.pop();
                int nse=i;
                int pse;
                if(!st.empty()){
                    pse=st.top();
                }
                else{
                    pse=-1;
                }
                maxArea=max((arr[elmI]*(nse-pse-1)),maxArea);
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
            maxArea=max((arr[elmI]*(nse-pse-1)),maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>>pSum(n,vector<int>(m,0));
        // build the pSum array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    if(i==0){
                        pSum[i][j]=1;
                    }
                    else{
                        pSum[i][j]=pSum[i-1][j]+1;
                    }
                }
                else{
                    pSum[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            int rowArea= largestRectangleArea_by_pSum_row(pSum[i]);
            maxArea= max(maxArea,rowArea);
        }
        return maxArea;
    }
};