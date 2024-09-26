Solution 1-:
Steps-:
1)question give u are at top left -> reach to bottom right.
  now i am at bottom right -> top left.
2)questions give u can go to bottom and right 
  me -> top and left.

Case1-:
when we are out of bound
if(n<0 || m<0) return 0;

Case2-:
if(n==0 and m==0) return grid[0][0];
when we are at destination return grid[0][0];

Case3-:
grid[n][m] + min(go_to_left,go_to_top).


Code-:
int helper(vector<vector<int>>& grid,int i,int j,int n,int m)
{
        if(i==0 and j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        
        
        return grid[i][j]+min(helper(grid,i-1,j,n,m),
                              helper(grid,i,j-1,n,m));
}

int minPathSum(vector<vector<int>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        int i=n-1;
        int j=m-1;
        return helper(grid,i,j,n,m);
}



Solution 2-:
Steps-:
1)Memo.

Code-:
int helper(int memo[201][201],vector<vector<int>>& grid,int n,int m)
{
        if(n==0 and m==0) return grid[0][0];
        if(n<0 || m<0) return 1e9;
        if(memo[n][m]!=-1) return memo[n][m];
        
        return memo[n][m]=grid[n][m]+min(helper(memo,grid,n-1,m),
                              helper(memo,grid,n,m-1));
}
int minPathSum(vector<vector<int>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        int memo[201][201];
        memset(memo,-1,sizeof(memo));
        return helper(memo,grid,n-1,m-1);
 }