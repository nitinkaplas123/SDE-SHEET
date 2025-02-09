https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

Question-:
1)Here question said we have to take the mod. of 1e5
2)which means our value will be in the range of 0 to 1e5.


Steps-:
1) Treat start as a source node and end as a destination node.
2) Here we have to find the min distance bw source to destination node where distance bw any node to any node is 1.
3) Shortest distance means -> using dikjistra algorithms.
4) start as source node -> put it into pq as {0,start} -> {steps,source node}.
5) each node is connected with n no. of nodes which is array elements.
6) make a dist array as well as the size is within the mod which is 1e5 so make a dist array of same.
7) update (dist[adjNode]>dist[node]+1)
     
     node =3  adjNode=6 

     so dist[6]>dist[3]+1      where 3 and 6 node is connected 
     dist[6]=dist[3]+1.

     and push it into pq.
8) when we got node==end which means this node reaches to its destination and its corresponding value is as steps.

9) return steps.



Time->O(n*mod*log(mod))  -> n for the array and we have 10^5 values and in pq its log(mod).
Space->O(mod)
Code-:
int mod=1e5;
int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n=arr.size();
        vector<int>dist(1e5+1,INT_MAX);
        dist[start]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        
        while(!pq.empty())
        {
            int steps=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(node==end)
            return steps;
            
            
            for(int i=0;i<n;i++)
            {
                int val=(node*arr[i])%mod;
                if(dist[val]>dist[node]+1)
                {
                    dist[val]=dist[node]+1;
                   
                    pq.push({dist[val],val});
                }
            }
        }
        return -1;
}



Solution 2-:
Steps-:
1) If we observe from sol1 its going like 0,1,2,3, .... as steps 
2) So we can do it using queue as well.


Time->O(mod*n)
Space->O(mod).
Code-:
int mod=1e5;
int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n=arr.size();
        vector<int>dist(1e5+1,INT_MAX);
        dist[start]=0;
    
        queue<pair<int,int>>q;
        q.push({0,start});
        
        while(!q.empty())
        {
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            if(node==end)
            return steps;
            
            
            for(int i=0;i<n;i++)
            {
                int val=(node*arr[i])%mod;
                if(dist[val]>dist[node]+1)
                {
                    dist[val]=dist[node]+1;
                   
                    q.push({dist[val],val});
                }
            }
        }
        return -1;
}