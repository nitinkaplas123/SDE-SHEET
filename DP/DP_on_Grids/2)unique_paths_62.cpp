Solution 1-:
Steps-:
1)using recursion 

Code-:
int helper(int row,int col,int m,int n)
{
        if(row==n-1 and col==m-1) return 1;
        if(row<0 || row>=n || col<0 || col>=m) return 0;

        return helper(row+1,col,m,n) + helper(row,col+1,m,n);
}
int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        return helper(i,j,m,n);
}



Solution 2-:
Steps-:
1)using memoization 

Code-:
int helper(int memo[100][100],int row,int col,int m,int n)
{
        if(row==m-1 and col==n-1) return 1;
        if(row<0 || row>=m || col<0 || col>=n) return 0;
        if(memo[row][col]!=-1) return memo[row][col];
        
        int res;
        res=helper(memo,row+1,col,m,n) + helper(memo,row,col+1,m,n);
        return memo[row][col]=res;
}

int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        int memo[100][100];
        memset(memo,-1,sizeof(memo));
        return helper(memo,i,j,m,n);
}