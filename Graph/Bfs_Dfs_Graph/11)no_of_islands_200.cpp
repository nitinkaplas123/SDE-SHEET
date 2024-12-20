Solution 1-:
Steps-:
1)Here simply we do dfs where we make visited array.
2)if grid[i][j]=='1' and !visited 
  call the dfs and go to all 4 directions and make visited if its finish 
3)return back to function and check another '1' and again calls the dfs and mark all its nearby cells with '1' as visited 
  and count the no. of islands like that. 


Code-: Time->O(n*m) Space->O(n*m)

int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int row,int col,int n,int m)
{
          visited[row][col]=true;
          
          for(int i=0;i<4;i++)
          {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false and grid[ur][uc]=='1')
            {
                dfs(grid,visited,ur,uc,n,m);
            }
          }
}

int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and visited[i][j]==false)
                {
                   dfs(grid,visited,i,j,n,m);
                   count++;
                }
            }
        }
        return count;
}




Solution 2-:
Steps-:
1)we are using visited array just if we visited-> 1 right now in future i dont want to use it again. 
  for that we make grid[i][j]='2' 


Code-: Time->O(N*M) Space->O(1) 
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<char>>& grid,int row,int col,int n,int m)
{
          grid[row][col]='2';
          for(int i=0;i<4;i++)
          {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and grid[ur][uc]=='1')
            {
                dfs(grid,ur,uc,n,m);
            }
          }
}

int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                   dfs(grid,i,j,n,m);
                   count++;
                }
            }
        }
        return count;
}