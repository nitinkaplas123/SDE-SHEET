Prims algo is also called as Min spanning tree.

Min spanning tree -> 
A spanning tree is defined as a tree-like subgraph of a connected,
undirected graph that includes all the vertices of the graph. Or, 
to say in Layman’s words, it is a subset of the edges of the graph 
that forms a tree (acyclic) where every node of the graph is a part
of the tree.

The minimum spanning tree has all the properties of a spanning tree with 
an added constraint of having the minimum possible weights among all 
possible spanning trees. Like a spanning tree, there can also be many
possible MSTs for a graph.

Minimum Spanning Tree (MST)

Properties of a Spanning Tree:
The spanning tree holds the below-mentioned principles:

1. The number of vertices (V) in the graph and the spanning tree is the same.
2. There is a fixed number of edges in the spanning tree which is equal to one less
   than the total number of vertices ( E = V-1 ).
3. The spanning tree should not be disconnected, as in there should only be a 
   single source of component, not more than that.
4. The spanning tree should be acyclic, which means there would not be any cycle 
   in the tree.
5. The total cost (or weight) of the spanning tree is defined as the sum of the
   edge weights of all the edges of the spanning tree.

Minimum Spanning Tree:
A minimum spanning tree (MST) is defined as a spanning tree that has the minimum 
weight among all the possible spanning trees.

Conclusion-:
A tree which having N nodes and N-1 edges and reachable from each other.

Intution -:
1)Same as dikjistra algorithms.
2)In dikjistra we are finding the shortest path from source 
  so u do 
  if(dist[v]>dist[u]+wt) 
  dist[v]=dist[u]+wt;

  BUT BUT here 
  we have to need 
  edges=V-1;
  so make dist[0]=0;

  now block the 0 index using 
  visited[0]=true;

  now go to there adjacent of 0 and check
  if(visited[adj[0]]==false and dist[adj[0]]>wt)
  {
    update it 
    put it into min heap.
  }
3)At last we have smallest weight in index 
  do the sum of all 
  and return sum.
  


Steps-:
1)Here we use the same idea as of dikjistra algo.
2)we make the dist array where we are stored the max INT_MAX value in all. At the end we have to update min value in it. 
  only dist[0]=0 because we are starting from there.
3)Here we are using the min heap which is depend upon the distance.
    pq.push({0,0});
    here we are pushing the {dist,node} node which is 0 and dist from 0=>0 is 0.
  1. now here we traverse in adjacency of node and we update the value in adjNode if we find the smallest value then it.
  2. if we get the smallest value update in dist[array] and push it into the min heap so that whatever we have in min heap
     we have to choose the min distance now from there. So this happen in flow. 
4)In the end we update the dist array and have a sum and return it.



Code-:
int spanningTree(int V, vector<vector<int>> adj[])
{
      bool visited[V]={false};
      int dist[V];
      for(int i=0;i<V;i++)
      {
          dist[i]=INT_MAX;
      }
      dist[0]=0;
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      
      pq.push({0,0});
      while(pq.empty()==false)
      {
          auto x=pq.top();
          pq.pop();
          int u=x.second;
          visited[u]=true;
          for(auto y:adj[u])
          { 
            int vertex=y[0];
            int wt=y[1];
            if(visited[vertex]==false and (dist[vertex]>wt))
            {
                dist[vertex]=wt;
                pq.push({dist[vertex],vertex});
            }
          }
      }
      
      int sum=0;
      for(int i=0;i<V;i++)
      {
          sum+=dist[i];
      }
      return sum;
}