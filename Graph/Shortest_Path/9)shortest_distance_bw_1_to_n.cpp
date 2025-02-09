https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


Question -:
1)From 1 to N where 1 is the source and N is the destination.
  we have to find the shortest distance bw them. 
2)and also give me the path from 1 to N which give u shortest distance.


### Question said 
1)first add the min distance from 1 to N.
2)then add the path of it.


Steps-:
1)When anyone say we have to find the shotest distance -> dikjistra algo came to your mind.
2)Now we have to find the path of shortest distance as well.
3)here we use the parent array. 

Parent array -:
vector<int>parent(n+1);
for(int i=0;i<=n;i++)
{
  parent[i]=i;
}


Now when we update the distance array with min distance -:
1)we update the dist[adj_node].
2)we push the pq.push(dist[adj_node],adj_node).
3)now here we update the parent array as well.

### How to print the path-:
 vector<int>path;
 int node=n;
 while(parent[node]!=node)
 {
    path.push_back(node);
    node=parent[node];
 }
 path.push_back(1);

1)path -> 1 to N.
2)start with N and upadte the node=parent[node].
3)till we reach to 1->1 
  because parent of 1node-> 1 because its a starting node.
4)when loop end we push 1 into it.
5)now add the dist[n].
6)reverse the path.
7)return the path.




Code-: Time->O(Elog(V))  -> E is the no. of edges V is the no. of vertexes
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
         vector<pair<int, int>> adj[n+1];
         for (int i = 0; i < m; i++) 
         {
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v, wt});
           adj[v].push_back({u, wt});
        }
        
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
                      greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        
        dist[1]=0;
                       
        pq.push({0,1});
        while(pq.empty()==false)
        {
            int node=pq.top().second;
            pq.pop();
            
            for(auto x:adj[node])
            {
                int adj_node=x.first;
                int wt=x.second;
                if(dist[adj_node]>dist[node]+wt)
                {
                    dist[adj_node]=dist[node]+wt;
                    pq.push({dist[adj_node],adj_node});
                    parent[adj_node]=node;
                }
            }
        }
        
        if(dist[n]==INT_MAX) return {-1};

        vector<int>path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
}



Solution 2-:
Steps-:
1)Same as up 
2) changes -> priority_queue -> queue.

Code-:
 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(n+1,INT_MAX);
        vector<int>hash(n+1);
        for(int i=1;i<=n;i++){
            hash[i]=i;
        }
        dist[1]=0;
        
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        queue<pair<int,int>>q;
        q.push({0,1});
        
        while(!q.empty())
        {
            int val=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto x:adj[node])
            {
                int adjNode=x.first;
                int wt=x.second;
                if(dist[adjNode]>dist[node]+wt)
                {
                    dist[adjNode]=dist[node]+wt;
                    q.push({dist[adjNode],adjNode});
                    hash[adjNode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        
        vector<int>ans;
        ans.push_back(n);
        int index=n;
        while(hash[index]!=index)
        {
            index=hash[index];
            ans.push_back(index);
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }