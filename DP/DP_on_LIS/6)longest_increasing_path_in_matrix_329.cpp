Solution 1-:
Steps-:
1)Here we run a loop at all points (n*n).
2)we go to every point and update the ans vector of vector with max increasing length 
3)and then return the maxx length which we stored in res variable.
4)in main function we update the maximum value and return at the end.

Time -> O(n*m)^2

Code-:
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
int helper(vector<vector<int>>&matrix,int row,int col,int n,int m,vector<vector<int>>&ans)
{
        queue<pair<int,int>>q;
        q.push({row,col});
        int res=1;
        while(q.empty()==false)
        {
            int rr=q.front().first;
            int cc=q.front().second;
            q.pop();
           

            for(int i=0;i<4;i++)
            {
                int ur=rr+r[i];
                int uc=cc+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m and matrix[ur][uc]<matrix[rr][cc])
                {
                    q.push({ur,uc});
                    ans[ur][uc]=1+ans[rr][cc];
                    res=max(res,ans[ur][uc]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=1;
            }
        }
        return res;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;
        vector<vector<int>>ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=helper(matrix,i,j,n,m,ans);
                res=max(res,val);
            }
        }
        return res;
}


Solution 2-:
Steps-:
1)Using recursion 
2)we pass a row,col and we go to all 4 directions -:
  1. if we are out of boundary return 0. 
  2. if curr_value<prev_value means its not increasing path return 0.
3)here at every point we find the max increasing path and store it in a res variable.
4)return res 

Time->O(4^n*m)
Code-:
int helper(vector<vector<int>>& matrix,int row,int col,int n,int m,int prev)
{
        if(row<0 || row>=n || col<0 || col>=m || matrix[row][col]<=prev) return 0;

        int up=helper(matrix,row-1,col,n,m,matrix[row][col]);
        int down=helper(matrix,row+1,col,n,m,matrix[row][col]);
        int left=helper(matrix,row,col-1,n,m,matrix[row][col]);
        int right=helper(matrix,row,col+1,n,m,matrix[row][col]);

        return 1+max(up,max(down,max(left,right)));
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=helper(matrix,i,j,n,m,-1);
                res=max(res,val);
            }
        }
        return res;
}



Solution 3-:
Steps-:
1)Using memo 

Code-:
int helper(int memo[201][201],vector<vector<int>>& matrix,int row,int col,int n,int m,int prev)
{
        if(row<0 || row>=n || col<0 || col>=m || matrix[row][col]<=prev) return 0;
        if(memo[row][col]!=-1) return memo[row][col];
        
       
        int up=helper(memo,matrix,row-1,col,n,m,matrix[row][col]);
        int down=helper(memo,matrix,row+1,col,n,m,matrix[row][col]);
        int left=helper(memo,matrix,row,col-1,n,m,matrix[row][col]);
        int right=helper(memo,matrix,row,col+1,n,m,matrix[row][col]);

        return memo[row][col]=1+max(up,max(down,max(left,right)));
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int memo[201][201];
        memset(memo,-1,sizeof(memo));
        int res=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=helper(memo,matrix,i,j,n,m,-1);
                res=max(res,val);
            }
        }
        return res;
}