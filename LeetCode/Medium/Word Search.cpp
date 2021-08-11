// URL : https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //traversing the board
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //if the character at 0th index matches in the word then we call the dfs function
                if(board[i][j]==word[0] && dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int index){
        //condition when the result is satisfactory
        if(index==word.length())
            return true;
        
        //base condition to end the backtrack/dfs
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index])
                return false;
        
        //changing the character to avoid re using the character
        char temp=board[i][j];
        board[i][j]='.';
        
        //calling the backtrack for its immediate neighbours
        bool ans= dfs(board,word,i+1,j,index+1) || dfs(board,word,i,j+1,index+1) 
            || dfs(board,word,i-1,j,index+1) || dfs(board,word,i,j-1,index+1);
        
        //putting the element back for other iteration
        board[i][j]=temp;
        
        //returning the ans calculated by the current instance
        return ans;
    }
};