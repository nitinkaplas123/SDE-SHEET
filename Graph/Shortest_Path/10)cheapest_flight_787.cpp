Solution 1-:
Steps-:
1)i am thinking using dikjistra algo.
2)pq.push({dist,{node,k}})

But its failed because of 
we update the smallest value in dist arr[] but its stops=1 and stops=2. 
beacuse of different paths we have.

### so here we make a priority on distance which is wrong.

Note-: we have to take care of stops first then distance.

1)So we make all the possible pairs {stops,node,dist} format.
2)so that we give priority to stops first.
3)in dikjistra algo we depends upon -:

if(stops>=0 && dist[adj_node]>dist[node]+wt)
{
    dist[adj_node]=dist[node]+wt;
    pq.push({dist[adj_node],{adj_node,stops-1}});
}


where dist[adj_node]>dist[node]+wt
this comparsion wrong.

because to reach ith node. 
we have for eg. 2 paths.
here at every path we have differnt {stops,cost}.

so add all the things in an priority_queue or queue 
because we have to go step by step -> stops=0 -> stops=1 ->stops=2.
so there is no need of using pq.

lets use queue 

### in below code its normal dikjistra algorithms which is not working for below case-:
n =7
flights =[[0,1,100],[0,2,100],[2,3,1],[3,4,600],[1,4,602],[4,5,6],[5,6,6]]
src =0
dst =6
k =3


Output->   -1
Expected-> 7





Wrong code -> priority -> gives to cost
Code-:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        int m=flights.size();
       
        //vector<pair<int,int>>adj[N];
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<m;i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,k}});

        while(pq.empty()==false)
        {
            int d=pq.top().first;
            int node=pq.top().second.first;
            int stops=pq.top().second.second;
            pq.pop();
            
            for(auto x:adj[node])
            {
                int adj_node=x.first;
                int wt=x.second;
                if(stops>=0 && dist[adj_node]>dist[node]+wt)
                {
                    dist[adj_node]=dist[node]+wt;
                    pq.push({dist[adj_node],{adj_node,stops-1}});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
}






Solution 1-:

Time->O(V+E)log(V)  where V is the no. of airports (vertexes) and E is the no. of edges bw airport.
Space ->O(V+E) -> for adjacency list and
The priority queue can hold up to 
O(V⋅k)
O(V⋅k) elements in the worst case, where k is the maximum number of stops.


Correct Code -> priority-> stops.
Code-:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         int m=flights.size();
         vector<vector<pair<int,int>>>adj(n);
         for(int i=0;i<m;i++)
         {
             int u=flights[i][0];
             int v=flights[i][1];
             int wt=flights[i][2];
             adj[u].push_back({v,wt});
         }
         vector<int>dist(n,INT_MAX);
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>pq;
         //{stops,{cost,node}}
         pq.push({0,{0,src}});
         dist[src]=0;

         while(!pq.empty())
         {
            int stops=pq.top().first;
            int cost=pq.top().second.first;
            int node=pq.top().second.second;
            
            pq.pop();

            for(auto x:adj[node])
            {
                int adjNode=x.first;
                int wt=x.second;
                if(stops<=k and dist[adjNode]>cost+wt)
                {
                    dist[adjNode]=cost+wt;
                    pq.push({stops+1,{dist[adjNode],adjNode}});
                }
            }
         }
         return (dist[dst]==INT_MAX)?-1:dist[dst];
}



Solution 2-:
Steps-:
0) if u see in pq we give priority to stops and go like this 0 stops =>1 stops. => 2 stops.
   this task can be done by queue data strcuture as well.
1)using queue{stops,node,cost}.
2)pls donot use dist[node] value because as i said 
  for a single node to reach at that node we have n ways.
  so at every path we have differnt stops and cost as well.


Time-> O(V*K + E)  where v is the no. of airports and k is given k why k here ?
       because BFS works in level by level 1st k=0 they traverse all the neighbour then k=1, k=2 upto k.
Space ->O(V+E+V⋅k)
Code-:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         int m=flights.size();
         vector<vector<pair<int,int>>>adj(n);
         for(int i=0;i<m;i++)
         {
             int u=flights[i][0];
             int v=flights[i][1];
             int wt=flights[i][2];
             adj[u].push_back({v,wt});
         }
         vector<int>dist(n,INT_MAX);
         queue<pair<int,pair<int,int>>>q;
         
         q.push({0,{0,src}});
         dist[src]=0;

         while(!q.empty())
         {
            int stops=q.front().first;
            int cost=q.front().second.first;
            int node=q.front().second.second;
            
            q.pop();

            for(auto x:adj[node])
            {
                int adjNode=x.first;
                int wt=x.second;
                if(stops<=k and dist[adjNode]>cost+wt)
                {
                    dist[adjNode]=cost+wt;
                    q.push({stops+1,{dist[adjNode],adjNode}});
                }
            }
         }
         return (dist[dst]==INT_MAX)?-1:dist[dst];
}