Solution 1-:
Steps-:
1)we start from all values of 1 row.
2)using helper we find the min answer.
3)store it in val variable. 

Code-: Time->O(3^N)
int helper(vector<vector<int>>& matrix,int row,int col,int n)
{
        if(row<0 || row>=n || col<0 || col>=n) return 1e9;
        if(row==n-1) return matrix[row][col];
        int down=helper(matrix,row+1,col,n);
        int ld=helper(matrix,row+1,col-1,n);
        int rd=helper(matrix,row+1,col+1,n);
        return matrix[row][col]+min(down,min(ld,rd));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int val=helper(matrix,0,i,n);
            ans=min(ans,val);
        }
        return ans;
}


Solution 2-:
Steps-:
1)using memo 


Code-: Time->O(N^3)
int helper(int memo[101][101],vector<vector<int>>&matrix,int row,int col,int n)
{
        if(row<0 || row>=n || col<0 || col>=n) return 1e9;
        if(row==n-1) return matrix[row][col];
        if(memo[row][col]!=-1) return memo[row][col];

        int down=helper(memo,matrix,row+1,col,n);
        int ld=helper(memo,matrix,row+1,col-1,n);
        int rd=helper(memo,matrix,row+1,col+1,n);
        return memo[row][col]=matrix[row][col]+min(down,min(ld,rd));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        int memo[101][101];
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++)
        {
            int val=helper(memo,matrix,0,i,n);
            ans=min(ans,val);
            memset(memo,-1,sizeof(memo));
        }
        return ans;
}



Solution 3-:
Steps-:
1)using tabulation 


Code-: 