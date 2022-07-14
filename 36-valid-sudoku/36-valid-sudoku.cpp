class Solution {
public:
     bool isPossible(int i,int j,vector<vector<char>>& board,char k){
        // no same elements in a row
        for(int x=0;x<9;x++){
            if(x!=j){
                if(board[i][x]==k){
                    return false;
                }
            }
            
        }
        // no same elements in a column
        for(int x=0;x<9;x++){
            if(i!=x){
                if(board[x][j]==k){
                    return false;
                }
            }
            
        }
        // no same elements in a grid
        int grid_row = (i/3)*3;
        int grid_col = (j/3)*3;
        for(int x=grid_row;x<grid_row+3;x++){
            for(int y = grid_col;y<grid_col+3;y++){
                if(i!=x && j!=y){
                   if(board[x][y]==k){
                        return false;
                    } 
                }
                
            }
        }
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isPossible(i,j,board,board[i][j])) return false;
                }
            }
        }
        return true;
    }
};