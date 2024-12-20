Steps-:
1)Its same as previous. 
2)in previous question we have to count the no. of islands 
3)here we have to find the maxx no. of 1s in every islands.
4)return the maxx are of it. 

Code-: Time->O(n*m) Space->O(n*m)
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int row,int col,int n,int m,int &count)
{
          count++;
          visited[row][col]=true;
          
          for(int i=0;i<4;i++)
          {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false and grid[ur][uc]==1)
            {
                dfs(grid,visited,ur,uc,n,m,count);
            }
          }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,false));
        int count=0;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                {
                   count=0;
                   dfs(grid,visited,i,j,n,m,count);
                   maxx=max(maxx,count);
                }
            }
        }
        return maxx;
}


Solution 2-:
Steps-:
1)instead of using visited array i modified the grid[i][j]=2 if we visited this 



Code-: Time->O(N*M) Space->O(1)
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<int>>& grid,int row,int col,int n,int m,int &count)
{
          count++;
          grid[row][col]=2;
          
          for(int i=0;i<4;i++)
          {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and  grid[ur][uc]==1)
            {
                dfs(grid,ur,uc,n,m,count);
            }
          }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       
        int count=0;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   count=0;
                   dfs(grid,i,j,n,m,count);
                   maxx=max(maxx,count);
                }
            }
        }
        return maxx;
}