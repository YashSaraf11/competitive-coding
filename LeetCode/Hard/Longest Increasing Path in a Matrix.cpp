// URL : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //variables to store the rows and columns for matrix
        int row=matrix.size(),col=matrix[0].size();
        
        //2D vector to store the maximum length encountered for that particular element to avoid recomputation
        vector<vector<int>>dp(row,vector<int>(col,1));
        
        //maxPath to store the result
        int maxPath=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
               maxPath=max(maxPath,dfs(matrix,dp,i,j,row,col));                                
        return maxPath;
    }
    
    //function to go in depth and find the maximum value for its connected element
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int row,int col){
        //if the value is not 1 then we have already calculated the value for that element and we can return
        if(dp[i][j]>1)
            return dp[i][j];            
        
        //to store the values returned by its immediate neighbours
        int a=1,b=1,c=1,d=1;
        if(i-1>=0 && matrix[i-1][j]<matrix[i][j])
            a=max(a,dfs(matrix,dp,i-1,j,row,col)+1);
        if(i+1<row && matrix[i+1][j]<matrix[i][j])
            b=max(b,dfs(matrix,dp,i+1,j,row,col)+1);
        if(j-1>=0 && matrix[i][j-1]<matrix[i][j])
            c=max(c,dfs(matrix,dp,i,j-1,row,col)+1);
        if(j+1<col && matrix[i][j+1]<matrix[i][j])
            d=max(d,dfs(matrix,dp,i,j+1,row,col)+1);
        
        //storing the maximum value from its neighbours to the dp vector
        dp[i][j]=max({a,b,c,d});
        
        //returning the value
        return dp[i][j];
        
    }
};