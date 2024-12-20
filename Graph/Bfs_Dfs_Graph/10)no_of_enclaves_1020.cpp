https://www.geeksforgeeks.org/problems/number-of-enclaves/0


Path to travel -:
1->1->1 because 1 is land.

Question -:
1)grid contains 0 and 1
2)from 1->1 we can move to different cell.
3)if grid==1 in that case we can move to 4 adjacent cells. 
4)if from 1->1->1 if we go out of boundary then we have to ignore that 1 from where we are starting.
5)if from 1->1->0 if means we encontered with 0 means now we cannot move. 
  so here your starting 1 is that 1 from which we cannot move out of boundary.

Task-:
Count the no. of 1s which cannot move out of boundary.


Steps-:
0) make queue and visited 2d array(false).
1)we can say that 1 (land) which is at boundary position -> is alway out of boundary.

Step1-:
traverse the grid matrix at boundary if grid[i][j]=1 
q.push(i,j)
visited[i][j]=true -> means this 1 -> is out of boundary.

Step2-:
traverse the queue and 
go in 4 directions 
if(grid[i][j]==1)
{
    qush into queue 
    visited[i][j]=true
}

false ->1 =>means count++;

Step3-:
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1 and visited[i][j]==false)
        count++;
    }
}
return count;

Code-: Time->O(N*M) Space->O(N*M)
int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
        }
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        
        while(q.empty()==false)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m and 
                   grid[ur][uc]==1 and visited[ur][uc]==false)
                {
                    visited[ur][uc]=true;
                    q.push({ur,uc});
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                count++;
            }
        }
        return count;
    }