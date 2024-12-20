https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1


Solution 1-:
Steps-:
1)using min heap and make another 2d array where i go to all 4 directions and update the 
  min sum in every grid->index.

Code-: Time->O(n*mlog(n*m))
       Space->O(n*m)
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int r1=source.first;
        int c1=source.second;
        
        int r2=destination.first;
        int c2=destination.second;
        
        if(grid[r1][c1]==0 || grid[r2][c2]==0)
        return -1;
        
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[r1][c1]=grid[r1][c1];
        
        priority_queue<pair<int,pair<int,int>>,
                      vector<pair<int,pair<int,int>>>,
                      greater<pair<int,pair<int,int>>>>pq;
                      
       
        pq.push({grid[r1][c1],{r1,c1}});
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        
        while(pq.empty()==false)
        {
            auto x=pq.top();
            pq.pop();
            
            int val=x.first;
            int row=x.second.first;
            int col=x.second.second;
            
            for(int i=0;i<4;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m and 
                   grid[ur][uc]==1 and ans[ur][uc]>val+grid[ur][uc])
                {
                    ans[ur][uc]=val+grid[ur][uc];
                    pq.push({ans[ur][uc],{ur,uc}});
                }
            }
        }
        return (ans[r2][c2]==INT_MAX)?-1:ans[r2][c2]-1;
}



Solution 2-:
Steps-:
1)its bfs so we can do it using queue as well.


Code-:
 int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       int n=grid.size();
       int m=grid[0].size();
       
       int sr=source.first;
       int sc=source.second;
       
       int dr=destination.first;
       int dc=destination.second;
       if(grid[sr][sc]==0 || grid[dr][dc]==0) return -1;
       
       vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
       vector<vector<int>>visited(n,vector<int>(m,false));
    //   priority_queue<pair<int,pair<int,int>>, 
    //                   vector<pair<int,pair<int,int>>>,
    //                   greater<pair<int,pair<int,int>>>>pq;
       queue<pair<int,pair<int,int>>>q;
       q.push({0,{sr,sc}});
       ans[sr][sc]=0;
       visited[sr][sc]=true;
       
       int r[4]={-1,1,0,0};
       int c[4]={0,0,-1,1};
       while(q.empty()==false)
       {
           int dist=q.front().first;
           int row=q.front().second.first;
           int col=q.front().second.second;
           q.pop();
           if(row==dr and col==dc) return ans[dr][dc];
           
           for(int i=0;i<4;i++)
           {
               int ur=row+r[i];
               int uc=col+c[i];
               if(ur>=0 and ur<n and uc>=0 and uc<m and grid[ur][uc]==1 and 
                 visited[ur][uc]==false and ans[ur][uc]>1+dist)
                 {
                     visited[ur][uc]=true;
                     ans[ur][uc]=1+dist;
                     q.push({ans[ur][uc],{ur,uc}});
                 }
           }
       }
       return -1;
}