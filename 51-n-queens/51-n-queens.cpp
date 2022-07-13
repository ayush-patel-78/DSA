class Solution {
public:
    vector<vector<string>> global;
    bool isPossible(vector<string> &board, int row, int col){
        // check same col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check upper left diagonal
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check upper right diagonal
        for(int i=row-1,j=col+1;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void nQueenHelper(vector<string> &board, int row){
        
        if(row == board.size()){
            global.push_back(board);
            return;
        }
        
        for(int i=0;i<board.size();++i){
            if(isPossible(board,row,i)){
                // make decision
                board[row][i] = 'Q';
                // next iteration
                nQueenHelper(board,row+1);
                // back-tracking
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
		
        vector<string> board(n,string(n,'.'));
        nQueenHelper(board,0);
        return global;
    }
};