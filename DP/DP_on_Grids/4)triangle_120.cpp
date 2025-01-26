Solution 1-:
Steps-:
1)right now -> triangle[row][col];
2)2 choose -:
  min(triangle[row+1][col],triangle[row+1][col+1]);

3)so there is choose -> DP 


Code-:
int helper(vector<vector<int>>& triangle,int row,int col,int n)
{
        if(row==n) 
        return triangle[row][col];
        return triangle[row][col]+min(helper(triangle,row+1,col,n),helper(triangle,row+1,col+1,n));
}
int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int row=0;
        int col=0;
        return helper(triangle,0,0,n-1);
}


Solution 2-:
Steps-:
1)using memo

Code-:
int helper(int memo[201][201],vector<vector<int>>& triangle,int row,int col,int n)
{
        if(row==n) 
        return triangle[row][col];
        if(memo[row][col]!=-1) 
        return memo[row][col];
        return memo[row][col]=triangle[row][col]+min(helper(memo,triangle,row+1,col,n),
                                                     helper(memo,triangle,row+1,col+1,n));
}
int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int row=0;
        int col=0;
        int memo[201][201];
        memset(memo,-1,sizeof(memo));
        return helper(memo,triangle,0,0,n-1);
}