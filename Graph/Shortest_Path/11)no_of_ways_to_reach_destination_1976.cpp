
Steps-:
1)Update the min value to every index in dist array.
2)Now our main task is to calculate no. of ways from source to destination with min distance.

3)So everytime when we see  this if condition
Case1 -:
 if(dist[adjNode]>cost+wt)
 {
        dist[adjNode]=cost+wt;
        ways[adjNode]=(ways[node]);
        pq.push({dist[adjNode],adjNode});
 }
 we update the dist[adjNode]=cost+wt;
 and here we update how many ways we have in graph to reach from node -> adjNode
 ways[adjNode]=ways[node].
 its coming first time so we have to add in pq as well.

Case2 -:
if(dist[adjNode]==cost+wt)
ways[adjNode]=(ways[adjNode]+ways[node])%mod;

means we have new path to reach adjNode from node but here distance is equal.
so here adjNode said hey node give me how much u store i will add in me.
ways[adjNode]=(ways[adjNode]+ways[node])%mod;


4)At the end min distance from source to destination will be store in dist[n-1] but at the same we store its no. of paths 
  which is stored in ways[n-1].
5)Return ways[n-1].



Time->O(V+E)log(V).
Code-:
int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<long long int,long long int>>>adj(n);

        for(int i=0;i<m;i++)
        {
            long long int u=roads[i][0];
            long long int v=roads[i][1];
            long long int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long int>dist(n,LLONG_MAX);
        vector<long long int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        int mod=1e9+7;

        priority_queue<pair<long long int,long long int>,
                      vector<pair<long long int,long long int>>,
                      greater<pair<long long int,long long int>>>pq;

        pq.push({0,0});
        while(!pq.empty())
        {
            long long int cost=pq.top().first;
            long long int node=pq.top().second;
            pq.pop();

            for(auto x:adj[node])
            {
                long long int adjNode=x.first;
                long long int wt=x.second;
                if(dist[adjNode]>cost+wt)
                {
                   dist[adjNode]=cost+wt;
                   ways[adjNode]=(ways[node]);
                   pq.push({dist[adjNode],adjNode});
                }
                else if(dist[adjNode]==cost+wt)
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
}