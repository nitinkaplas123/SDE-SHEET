Question:
1. A graph is called bipartite only if every connected component inside 
it is bipartite.
2. If even one component is not bipartite, then the entire graph is not bipartite.



Solution 1-:
Steps-:
1)same idea as m colouring question. 

Code-:
bool isValid(vector<vector<int>>&adj,vector<int>&color,int index,int i)
{
         for(auto x:adj[index])
         {
            if(color[x]==i)
            return false;
         }
         return true;
}
bool helper(vector<vector<int>>&adj,vector<int>&color,int index,int n)
{
        if(index==n)
        return true;
        for(int i=1;i<=2;i++)
        {
           if(isValid(adj,color,index,i))
           {
              color[index]=i;
              if(helper(adj,color,index+1,n))
              return true;
              color[index]=0;
           }
        }
        return false;
}
bool isBipartite(vector<vector<int>>&adj) {
        int n=adj.size();
        vector<int>color(n);
        return helper(adj,color,0,n);
        
}



Solution 2-:
Steps-:
1)using prev idea 0->1 ->0 ->1.


Time->O(V+E)
Code-:
bool bfs(vector<vector<int>>& graph,int i,vector<int>&color,queue<int>q,vector<int>&visited)
{
       color[i]=0;
       q.push(i);
       while(!q.empty())
       {
            int node=q.front();
            visited[node]=true;
            q.pop();

            for(auto x:graph[node])
            {
                if(color[x]!=-1)
                {
                    if(color[x]==color[node]) return false;
                }
                else
                {
                  color[x]=!color[node];
                  q.push(x);
                }
            }
        }
        return true;
}
bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
       
        vector<int>visited(n,false);

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                 if(bfs(graph,i,color,q,visited)==false)
                 return false;
            }
        }
        return true;
}



Solution 2-:
Steps-:
1)using dfs 

Code-:
bool dfs(vector<vector<int>>& graph,int node,int col,vector<int>&color,vector<int>&visited)
{
       color[node]=col;
       visited[node]=true;
       for(auto x:graph[node])
       {
          if(color[x]==-1)
          {
              if(dfs(graph,x,!col,color,visited)==false)
              return false;
          }
          else if(color[x]==color[node])
          return false;
       }
       return true;
}
bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
       
       
        vector<int>visited(n,false);
       
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                 if(dfs(graph,i,0,color,visited)==false)
                 return false;
            }
        }
        return true;
}



Solution 3:
Steps:
1) Without visited array.
   inplace of visited[i]==false, we use color[i]==-1



Code:
bool dfs(vector<vector<int>>& graph,int node,int col,vector<int>&color)
{
        color[node]=col;
        for(auto x:graph[node])
        {
            if(color[x]==-1)
            {
                if(!dfs(graph,x,!col,color))
                return false;
            }
            else if(color[x]==color[node])
            return false;
        }
        return true;
}
bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);

        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(graph,i,0,color))
                return false;
            }
        }
        return true;
}