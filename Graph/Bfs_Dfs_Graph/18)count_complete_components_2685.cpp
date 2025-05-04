Solution 1:

Steps:
1)In undirected graph -:
  if there are n nodes then there is n*(n-1)/2 no. of edges.

Nodes=n.
Edges=n*(n-1)/2.

for eg. 

  1----2
   \  /
    3 

Nodes=3
Edges=3*(2)/2 => 3

or 
if we count 2times edges 
1--2 
2--1 

then 
Nodes=n 
Edges=n*(n-1)


Nodes -: 1,2,3 
Edges -: 1-2, 2-1, 2-3, 3-2, 3-1, 1-3

Nodes=3 
Edges=3*(3-1) 


Steps:
1)When we marked visited means                 -: there is new node. 
2)And whenver we entered into for loop of node -: that means there is an edge.


0 -> 1,2
1 -> 0,2 
2 -> 0,1 
3 -> 4 
4 -> 3
5


For 0,1,2
Nodes : 3 
Edges : 6 

For 3,4
Nodes : 2 
Edges : 2

For 5 
Nodes : 1
Edges : 0 



Time Complexity : O(V+E)
Space : O(V+E)  for adj list storage.
Code:
void dfs(vector<int>adj[],int src,int &e,int &n,vector<int>&visited)
{
        visited[src]=true;
        n++;

        for(auto x:adj[src])
        {
            e++;
            if(visited[x]==false)
            dfs(adj,x,e,n,visited);
        }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                int e=0;
                int n=0;
                dfs(adj,i,e,n,visited);
                if(e==(n*(n-1)))
                count++;
            }
        }
        return count;
}
