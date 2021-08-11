// URL : https://leetcode.com/problems/valid-sudoku/submissions/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //arrays to store if we encounter the number before
        int row[9][9]={0},col[9][9]={0},block[9][9]={0};
            
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                //checking if the element is not '.' then we check and update the arrays
                if(board[i][j]!='.'){
                    //to store the number at the current position
                    int currNum=board[i][j]-'0'-1;
                    
                    //calculating the block number
                    int blockNo= (i/3)*3+j/3;
                    
                    //checking if the number is already been encountered in the row,column,block
                    if(row[i][currNum] || col[j][currNum] || block[blockNo][currNum])
                        return false;
                    
                    //otherwise we update the row,column,block for the particular element in the grid
                    row[i][currNum]=col[j][currNum]=block[blockNo][currNum]=1;
                }
            }                
        }
        
        return true;
    }
};