reference-> https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60
just see first 13 mins. 

Solution 1-:
Steps-:
for eg. v=4 and m=3
1)here we start with 0 node. 
2)at each node we have m options here m=3 means at each vertex/node we can color with m=1,m=2,m=3. 
3)but we have to check first can we color the node with i 
  for that we have to check using isSafe function 
  where we check if adjacent vertex of node have color i 
  then we cannot give this color i to node.
4)if (isSafe is true)
  store the node->i(color)
  m[node]=i; 

5)go to deep in tree or say that for different vertex ko color dene k lea. 
6)at the end if(node/index==v) it means we are successfully give me color to all and we are take care of all adjacent as well.




        f(0,4,)

In the worst case, the DFS tree has a depth of N, and at each step, we have M choices.
The function isValid() runs O(N) per node.
Total Complexity  -> M^V *N 



Time-> M^V  where M is the no. of colours and V is the no. of vertex we have.
      how? -> 2^n -> here we have n elements and at each elements we have 2 choices 
      here -> we have V no. of vertexes and at each vertex we have M choices. 

Space Complexity:
Adjacency List: O(E) to store the edges.
Color Map: O(v) to store the color of each vertex.
Recursive Stack: In the worst case, the depth of recursion is O(v).

Code-:
bool isSafe(int node,int number,vector<int>adj[],unordered_map<int,int>&color)
{
        for(auto x:adj[node])
        {
            if(color[x]==number)
            return false;
        }
        return true;
}

bool helper(int node,int v,int m,vector<int>adj[],unordered_map<int,int>&color)
{
        if(node==v) return true;
        for(int i=1;i<=m;i++)
        {
            if(isSafe(node,i,adj,color))
            {
                color[node]=i;
                if(helper(node+1,v,m,adj,color))
                return true;
                else
                color[node]=0;
            }
        }
        return false;
}

bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<int>adj[v];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,int>color(v);
        return helper(0,v,m,adj,color);
}