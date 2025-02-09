Refernce ->
https://www.youtube.com/watch?v=0ytpZyiZFhA

Question -:

[1,2,2]
[3,8,2]
[5,3,5]

Paths -> from grid[0][0] -> grid[n-1][n-1]
diff two bw 
1) 1->2->2->2->5
    1   0  0  3   -> maxEfforts -> 3 

2) 1->3->5->3->5 
    2   2  2   2  -> maxxEfforts -> 2 

3) 1->2->8->3->5 
    1   6  5   2  -> maxxEfforts -> 6 

I want minEfforts in all paths -> 2 

O/P -> 2.  


Intution -:
1) find the min path 
2) from left top -> bottom right. 

From here i think about dikjistra algotithm.


Steps-:
1)We make min heap of {diff,{row,col}}.
2)We make dist 2d array where i put the diff bw 2 elements and i update the max in that 
  path.
3)for this i fill dist 2d array with (INT_MAX).
   dist[0][0]=0;
   because single element difference is 0.
4) go to 4 directions and update the dist 2d array with smallest value 
   diff -> current diff where we are standing right now.
   maxEffort-> diff bw two elements 
   dist[ur][uc]=max(maxEffort,diff).

5)Do the dry run onces.




Code-: Time->O(N*M(log(m*n)))
int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        while(pq.empty()==false)
        {
            int maxx_diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m)
                {
                    int diff=abs(heights[ur][uc]-heights[row][col]);
                    diff=max(maxx_diff,diff);
                    if(dist[ur][uc]>diff)
                    {
                        dist[ur][uc]=diff;
                        pq.push({dist[ur][uc],{ur,uc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];                     
}



Solution 2-:
Steps-:
1)Same instead of priority_queue we change that in queue. 

Code-:
int minimumEffortPath(vector<vector<int>>&grid) {
          int n=grid.size();
          int m=grid[0].size();

          vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        //   priority_queue<pair<int,int>,vector<pair<int,int>>,
        //                  greater<pair<int,int>>>pq;
          queue<pair<int,int>>pq;
          vector<vector<int>>visited(n,vector<int>(m,false));
          dist[0][0]=0;
          pq.push({0,0});
          visited[0][0]=true;

          int r[4]={-1,1,0,0};
          int c[4]={0,0,-1,1};
          while(pq.empty()==false)
          {
             int row=pq.front().first;
             int col=pq.front().second;
             pq.pop();

             for(int i=0;i<4;i++)
             {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m)
                {
                    int diff=abs(grid[ur][uc]-grid[row][col]);
                    diff=max(diff,dist[row][col])x;
                    if(dist[ur][uc]>diff)
                    {
                      dist[ur][uc]=diff;
                      pq.push({ur,uc});
                    }
                }
             }
          }
          return dist[n-1][m-1];
   }