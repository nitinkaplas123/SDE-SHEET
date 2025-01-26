Solution 1-:
Steps-:
1) same as grid1 just where we have obstacles (grid[row][col]==1) return 0; from here as well.
Code-:
int helper(vector<vector<int>>&grid,int row,int col,int n,int m)
{
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==1)
        return 0;

        if(row==n-1 and col==m-1)
        return 1;
       
        int down=helper(grid,row+1,col,n,m);
        int right=helper(grid,row,col+1,n,m);
        return down+right;
}

int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int n=grid.size();
        int m=grid[0].size();
        return helper(grid,0,0,n,m);
}



Solution 2-:
Steps-:
1)using memo 

Time->O(N*M)  Space->O(N*M)
Code-:
int helper(int memo[101][101],vector<vector<int>>&grid,int row,int col,int n,int m)
{
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==1)
        return 0;

        if(row==n-1 and col==m-1)
        return 1;
        if(memo[row][col]!=-1) return memo[row][col];
       
        int down=helper(memo,grid,row+1,col,n,m);
        int right=helper(memo,grid,row,col+1,n,m);
        return memo[row][col]=down+right;
}
int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int n=grid.size();
        int m=grid[0].size();
        int memo[101][101];
        memset(memo,-1,sizeof(memo));
        return helper(memo,grid,0,0,n,m);
}