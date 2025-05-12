Solution 1:

Steps:
1)Using dfs 


Time -> O(K*M*N)
Space ->O(M*N)

Code:
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<int>>& grid,int row,int col,int n,int m,int val,int &count)
{
    count++;
    grid[row][col]=INT_MAX;

    for(int i=0;i<4;i++)
    {
        int ur=row+r[i];
        int uc=col+c[i];
        if(ur>=0 and ur<n and uc>=0 and uc<m and grid[ur][uc]<val)
        dfs(grid,ur,uc,n,m,val,count);
    }
}
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int k=queries.size();
    int n=grid.size();
    int m=grid[0].size();
    vector<int>ans;
    vector<vector<int>>mat=grid;
    for(int i=0;i<k;i++)
    {
        int count=0;
        if(mat[0][0]<queries[i])
        dfs(mat,0,0,n,m,queries[i],count);
        ans.push_back(count);
        mat=grid;
    }
    return ans;
}



Solution 2:
Steps:
1) we sorted the query in increasing order and store it corressponding index as well.

[5,6,2]

[{5,0},{6,1},{2,2}]

sort 
[{2,2},{5,0},{6,1}]

2) Now we are solving for value -> 2 
   how many elements are smaller than value -> 2
   using minheap we solved 
   where we start from top left and traverse into its 4 direction.
   and mark visited if we add it into pq.

3) now suppose for value-> 2 my count is -> 2
   now when i traverse for value->5 

   is there any need to start from start (top left index)?
   now right if for value-> 2 my count is -> 2 
   then for value->5 that 2 is also the count for value->5 na ?
   so we start it from where value->2 left.


Note : Do dry run.


Time Complexity -: O(N*Mlog(m*n))
Space ->O(M*N)
Code:

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
{
    int k=queries.size();
    int n=grid.size();
    int m=grid[0].size();
    vector<int>ans(k);
    vector<pair<int,int>>v;
    for(int i=0;i<k;i++)
    {
    v.push_back({queries[i],i});
    }
    sort(v.begin(),v.end());
    vector<vector<int>>visited(n,vector<int>(m,false));
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({grid[0][0],{0,0}});
    visited[0][0]=true;

    int r[4]={-1,1,0,0};
    int c[4]={0,0,-1,1};

    int count=0;
    for(int i=0;i<k;i++)
    {
        int val=v[i].first;    // 2
        int index=v[i].second; // 2 

        while(!pq.empty() and pq.top().first<val)
        {
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            count++;
            
            for(int i=0;i<4;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];
                if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false)
                {
                visited[ur][uc]=true;
                pq.push({grid[ur][uc],{ur,uc}});
                }
            }
        }
        ans[index]=count;
        }
        return ans;
}