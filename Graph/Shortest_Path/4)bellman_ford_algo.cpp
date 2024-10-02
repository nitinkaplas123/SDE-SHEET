Bellmamd ford is also used to calaculate the shortest path from source to all the vertices.
same working as of dikjistra algorithms.

BUT BUT BUT.
1.Dikjistra algo failed in -ve weight cycle.
2.If the graph has -ve cycle the dikjistra giving me TLE.
  its running running never ending the priority queue.

Bellmond ford -:
1)helps for -ve weight.
2)helps to detect the -ve cycle.
3)It is applied on Directed graph.

How we can applied on Undirected graph ?
1)In DG we are given -:
   u->v weight is 5 

 Given in DG 
 u->v weight is 5 
 we have to add in the DG like-:
 v->u weight is 5.


Question -:
1)Can u detect the given graph has -ve cycle or not?

-ve cycle means if we sum of all the weight edges of the graph if sum<0 then return true
means yes there is -ve cycle.

eg.
1->2 => -2 
2->3 => -1
3->1 => 2

sum=> -2+2+-1
   => -1 

return true -> yes its -ve cycle.




Steps-:
1)Here we have to traverse or relax all the edges N-1 times.
2)We have to make the dist array same as dikjistra and make all as __INT_MAX__
  vector<int>dist(V,INT_MAX)
  dist[src]=0;
3)Now what do you means by relax (N-1) times.
  here we have to traverse all the edges 
  u->v->wt to update our dist[v] with min value.

  1)Traverse all the edges 1st time -> 1 one relax.
  2)Same steps we have to do n-1 times.
  3)Means we have to traverse all the edges n-1 times.


Questions-:
1)Why n-1 times 
Answer-:
Edges can be in any order.

eg-:
(u,v,wt)
(3,4,1)
(2,3,1)
(1,2,1)
(0,1,1)

graph -:

 1  1  1  1
0->1->2->3->4

here do the dry run 
to update the dist array we have to do N-1 relax means we have to run all edges (n-1) time.


2)How to detect the graph has -ve cycle.
 
Answer-:
we know that we have to do n-1 relax to find the shorest path from the graph even if its -ve weight edges.
only because of -ve weight edges we have to do n-1 times.

But if we do one more time with if n=6 and we do 5 times which means my dist array is ready
but if we do 6th time and if again my dist array is updated with less value 
it means there is -ve weighted edge cycle bcz only in this case 6th its still reduce.


note-:
bcz we proved that using n-1 iteration we can find the shorest distance from source.
even doing nth iteration again its reduced it means there is -ve weight edge cycle.


Steps-:
1)here we make dist array with INT_MAX.
2)dist[S]=0;
3)do the relax for v-1 time and there if dist[u] is 1e8 means we cannot update its adj node na.
4)if at doing nth relax if the dit[u] is updated then we have to return {-1} 
  else 
  return dist {bcz it means there is no -ve cycle.}

Code-: Time->O(V*E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       vector<int>dist(V,1e8);
       dist[S]=0;
       for(int i=0;i<V-1;i++)
       {
           for(auto x:edges)
           {
               int u=x[0];
               int v=x[1];
               int wt=x[2];
               if(dist[u]!=1e8 and dist[v]>dist[u]+wt)
               dist[v]=dist[u]+wt;
           }
       }
       
       // nth iteration check if its update the dist[v] then return -1 bcz there is -ve weight cycle.
       for(auto x:edges)
       {
           int u=x[0];
           int v=x[1];
           int wt=x[2];
           if(dist[u]!=1e8 and dist[v]>dist[u]+wt)
           return {-1};
       }
       return dist;
}