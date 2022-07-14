class Solution {
public:
    
    // vector<vector<char>> board2(9,vector<char>(9,'.'));
    bool isPossible(int i,int j,vector<vector<char>>& board,char k){
        // no same elements in a row
        for(int x=0;x<board.size();x++){
            if(board[i][x]==k){
                return false;
            }
        }
        // no same elements in a column
        for(int x=0;x<board.size();x++){
            if(board[x][j]==k){
                return false;
            }
        }
        // no same elements in a grid
        int grid_row = (i/3)*3;
        int grid_col = (j/3)*3;
        for(int x=grid_row;x<grid_row+3;x++){
            for(int y = grid_col;y<grid_col+3;y++){
                if(board[x][y]==k){
                    return false;
                }
            }
        }
        return true;
        
    }
    bool helper(vector<vector<char>>& board){
       
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                       if(isPossible(i,j,board,k)){
                            board[i][j]=k;
                           bool check;
                            check = helper(board);
                           if(check==true)return true;
                           else board[i][j]='.';   
                        } 
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};