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
n =
4
flights =
[[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
src =
0
dst =
3
k =
1





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






Solution 2-:
Steps-:
1)using queue{stops,node,cost}.
2)pls donot use dist[node] value because as i said 
  for a single node to reach at that node we have n ways.
  so at every path we have differnt stops and cost as well.


Note-:
for(auto x:adj[node])
{
    int adj_node=x.first;
    int wt=x.second;
    if(cost+wt<dist[adj_node] and stops<=k)
    {
        dist[adj_node]=cost+wt;
        pq.push({stops+1,{adj_node,dist[adj_node]}});
    }
}

3)here here we compare like cost+wt -> right
  dist[node]+wt<dist[adj_node] is wrong.

  because there may be differnt {stops,cost} for same node.


Code-: Time->Elog(V)  but here we are using queue ->
       Time->E ->    no. of edges  -> O(M)
 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        int m=flights.size();
       
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
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});
        
        while(q.empty()==false)
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            
            if(stops>k)
            continue;
            
            for(auto x:adj[node])
            {
                int adj_node=x.first;
                int wt=x.second;
                if(cost+wt<dist[adj_node] and stops<=k)
                {
                    dist[adj_node]=cost+wt;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
}