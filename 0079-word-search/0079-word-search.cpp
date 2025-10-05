class Solution {
public:

    bool find_comb(int row,int col,int index,vector<vector<char>>& board, string word){
        if(index==word.size()){
            return true;
        }
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size()|| board[row][col]!=word[index]){
            return false;
        }
        char temp= board[row][col];
        board[row][col]='#';
        bool found= find_comb(row,col+1,index+1,board,word)||find_comb(row,col-1,index+1,board,word)||find_comb(row+1,col,index+1,board,word)||find_comb(row-1,col,index+1,board,word);
        board[row][col]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(find_comb(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};