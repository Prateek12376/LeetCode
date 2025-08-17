class Solution {
public:
    int find_max_row_index(vector<vector<int>>& mat, int n, int column){
        int maxValue=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][column]>maxValue){
                maxValue = mat[i][column];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int maxRowIndex = find_max_row_index(mat,n,mid);
            int left=mid-1;
            int right=mid+1;
            if(left>=0){
                left=mat[maxRowIndex][mid-1];
            }
            else{
                left =-1;
            }
            if(right<m){
                right=mat[maxRowIndex][mid+1];
            }
            else{
                right=-1;
            }
            if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
                return{maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};