class Solution {
public:
    int largest_sumA(vector<int>& height){
        int n=height.size();
        stack<int>st;
        int maxA=0;

        // we have to find nse and pse 
        for(int i=0;i<n;i++){
            while(!st.empty() && height[i]<height[st.top()]){
                int elmI = st.top();
                st.pop();
                int nse=i; 
                int pse;
                if(!st.empty()){
                    pse=st.top();
                }
                else{
                    pse=-1;
                }
                maxA= max(maxA,height[elmI]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int elmI=st.top();
            st.pop();
            int pse;
            if(!st.empty()){
                pse=st.top();
            }
            else{
                pse=-1;
            }
            maxA= max(maxA,height[elmI]*(nse-pse-1));
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>preSumH(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    if(i==0){
                        preSumH[i][j]=1;
                    }
                    else{
                        preSumH[i][j]=preSumH[i-1][j]+ 1;
                    }
                }
                else{
                    preSumH[i][j]=0;
                }
            }
        }
        int maxiS=INT_MIN;
        for(int i=0;i<n;i++){
            maxiS= max(maxiS,largest_sumA(preSumH[i]));
        }
        return maxiS;
    }
};