Solution 1-:
Steps-:
1)Here we are using dikjistra algo.
2)Using this algo we find all the min time taken to reach from given source node to all the nodes.
3)This time taken by every node is filled in dist array.
4)Now we fill with min time taken now we just have to get the max of all time taken by the nodes.
  if max time taken by any node is -> INT_MAX
  it means that particular node is not reachable.
  so we return -1 in that case.


Time->O(mlog(n)) 
Space ->O(m+n)
Code-:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++)     // O(m)
        {
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int time=times[i][2];
            adj[u].push_back({v,time});
        }

        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});

        while(!pq.empty())    //O(mlog(n))
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();


            for(auto x:adj[node])
            {
                int adjNode=x.first;
                int wt=x.second;
                if(dist[adjNode]>time+wt)
                {
                    dist[adjNode]=time+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int ans=dist[0];
        for(int i=1;i<n;i++){   //O(n)
            ans=max(ans,dist[i]);
        }
        return (ans==INT_MAX)?-1:ans;
}