https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1

Steps-:
1)here we need to find the min sum path from {0,0} -> {n-1,n-1}.
2)here i make a ans->2d array where we initialise the INT_MAX in all.
  but at first -> ans[0,0]=grid[0][0].
3)here we make min heap {value,{row,col}}.
4)go to all 4 directions and 
  if(ans[ur][uc]>val+grid[ur][uc])
  {
    update the ans[ur][uc]=val+grid[ur][uc].
    and push into queue 
  }

Min heap -> because out of all we choose the mini value first.
            but we have to go in all the directions.


Code-:
int minimumCostPath(vector<vector<int>>& grid) 
{
       int n=grid.size();
       int m=grid[0].size();
       
       vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       
       pq.push({grid[0][0],{0,0}});
       dist[0][0]=grid[0][0];
       
       int r[4]={-1,1,0,0};
       int c[4]={0,0,-1,1};
       while(!pq.empty())
       {
           int val=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           
           if(row==n-1 and col==m-1)
           return val;
           
           for(int i=0;i<4;i++)
           {
               int ur=row+r[i];
               int uc=col+c[i];
               if(ur>=0 and ur<n and uc>=0 and uc<m and dist[ur][uc]>val+grid[ur][uc])
               {
                   pq.push({val+grid[ur][uc],{ur,uc}});
                   dist[ur][uc]=val+grid[ur][uc];
               }
           }
       }
       return -1;
  }