Question-:
1)u are given 0_1 matrix and distance bw two adjacent cell is 1.
2)we have to find nearest 0 distance from each cell.

using bfs approach.
1)we know that if your cell is mat[i][j]=0 
  then its distance from 0 is 0
  because cell itself is 0.
2)can we take that as source cell because 0->0 => distance is 0.
  
same question we are given graph and source we have to find the smallest distance 
from source to each cell having unit distance from two adjacent cells.


Steps-:
1)we make here visited 2d array and queue.
2)we run a matrix if its current cell is 0 add its pair into queue.
3)Now run a normal bfs using queue and at each cell we have to go in all the 4 directions
  and update the mat[i][j] as smallest as possible.



Code-: Time->O(n*m)  Space->O(N*M)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();

       queue<pair<int,int>>q;
       vector<vector<int>>visited(n,vector<int>(m,false));

       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            if(mat[i][j]==0)
            {
                q.push({i,j});
                visited[i][j]=true;
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
              if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false)
              {
                 mat[ur][uc]=1+mat[row][col];
                 q.push({ur,uc});
                 visited[ur][uc]=true;
              }
           }
       }
       return mat;
    }