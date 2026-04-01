class Solution {
public:
    bool checkValidity(int row,int col,vector<vector<char>>& board){
        map<char,int>mR;
        map<char,int>mC;
        map<char,int>box;
        
        // for col
        for(int i=0;i<9;i++){
            if(board[row][i]!='.'){
                mC[board[row][i]]++;
            }
        }
        if(mC[board[row][col]]>1){
            return false;
        }
        // for row
        for(int i=0;i<9;i++){
            if(board[i][col]!='.'){
                mR[board[i][col]]++;
            }
        }
        if(mR[board[row][col]]>1){
            return false;
        }
        // for boxes
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]!='.'){
                    box[board[i][j]]++;
                }
            }
        }
        if(box[board[row][col]]>1){
            return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!checkValidity(i,j,board)){
                    return false;
                }
            }
        }
        return true; 
    }
};