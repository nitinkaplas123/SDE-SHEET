Solution 1-:
Steps-:
1)using dikjistra algo idea.
2)here we have to go to all 8 directions.
3)they said we can go from only in 0->paths.
4)here i change the 0->1 and 1->0.


Code-:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) grid[i][j]=0;
                else grid[i][j]=1;
            }
        }
        if(grid[0][0]==0 || grid[n-1][n-1]==0)
        return -1;
        
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        ans[0][0]=grid[0][0];
        
        priority_queue<pair<int,pair<int,int>>,
                      vector<pair<int,pair<int,int>>>,
                      greater<pair<int,pair<int,int>>>>pq;
                      
       
        pq.push({grid[0][0],{0,0}});
        
        int r[8]={-1,1,0,0,-1,-1,1,1};
        int c[8]={0,0,-1,1,-1,1,-1,1};
        
        while(pq.empty()==false)
        {
            auto x=pq.top();
            pq.pop();
            
            int val=x.first;
            int row=x.second.first;
            int col=x.second.second;
            
            for(int i=0;i<8;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<n and 
                   grid[ur][uc]==1 and ans[ur][uc]>val+grid[ur][uc])
                {
                    ans[ur][uc]=val+grid[ur][uc];
                    pq.push({ans[ur][uc],{ur,uc}});
                }
            }
        }
        return (ans[n-1][n-1]==INT_MAX)?-1:ans[n-1][n-1];
}



Solution 2-:
Steps-:
1)using simple shortest path in undirected graph having unit weight.
2)using queue,visited array,ans 2d array.

Same same steps-:
Code-: Time->O(n*n) Space->O(n*n)
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;


        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        vector<vector<int>>visited(n,vector<int>(n,false));

        q.push({0,0});
        visited[0][0]=true;
        ans[0][0]=1;

        int r[8]={-1,1,0,0,-1,-1,1,1};
        int c[8]={0,0,-1,1,-1,1,-1,1};
        while(q.empty()==false)
        {
            auto x=q.front();
            q.pop();

            int row=x.first;
            int col=x.second;

            for(int i=0;i<8;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<n and grid[ur][uc]==0 
                   and visited[ur][uc]==false)
                {
                    visited[ur][uc]=true;
                    ans[ur][uc]=1+ans[row][col];
                    q.push({ur,uc});
                }
            }
        }
        return (ans[n-1][n-1]==INT_MAX)?-1:ans[n-1][n-1];
}



Solution 3-:
Steps-:
1)without using visited array and new ans 2d array.
2)we modified the grid 2d array and when we reach to first time [n-1][n-1] then we return the 
  whatever we store over there.


Code-:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;


        queue<pair<int,int>>q;
        q.push({0,0});

        grid[0][0]=1;

        int r[8]={-1,1,0,0,-1,-1,1,1};
        int c[8]={0,0,-1,1,-1,1,-1,1};
        while(q.empty()==false)
        {
           auto x=q.front();
           q.pop();

           int row=x.first;
           int col=x.second;

           if(row==n-1 and col==n-1)
           return grid[row][col];
           
           for(int i=0;i<8;i++)
           {
              int ur=row+r[i];
              int uc=col+c[i];

              if(ur>=0 and ur<n and uc>=0 and uc<n and grid[ur][uc]==0)
              {
                 grid[ur][uc]=1+grid[row][col];
                 q.push({ur,uc});
              }
           }
        }
        return -1;
}