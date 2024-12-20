Question-:
1)Terminal Nodes-:
A node where we have 0 outDegree.

2)Safe nodes.
A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

for eg.
          0     1     2   3   4   5  6 
graph = [[1,2],[2,3],[5],[0],[5],[],[]]

here 0->node is connected with 1 and 2.
     1->node is connected with 2 and 3.
     2->node is connected with 5.
     3->node is connected with 0.
     4->node is connected with 5.
     5->node is connected with nothing.
     6->node is connected with nothing.


Can we say that 5 and 6 nodes have outDegree 0?
yes.

can we say that 5 and 6 are the terminal nodes.

Terminal nodes -> 5 and 6.
and this terminal node has 0 path or we can say that terminal to terminal means its called as safe nodes.




2)Safe nodes.
check all the nodes and at each node if we have n path so at every path if we reach to terminal node then we can 
say that particulaer node is safe node.

dry run -:
Note make a graph diagram on notebook.
Check all the paths from each node and if all the path are reached to terminal node which is here 5 and 6.
then we can say that that particular node is safe node.



Intution-:
1)Question said its directed graph.
2)OutDegree is 0 that is your terminal node and that is also your safe node.
3)From here i am thinking of topological sort.


Topological Sort-:
1)In topological Sort we make inDegree vector and those inDegree is 0 we push into queue and 
  the value which is added in queue that is my answer and we normally traverse its adjacency list and make 
  inDegree[val]--;
2)Same here we can do.
3)here question said outDegree -> 0 
  in topological inDegree-> 0.
4)How we can converted into topo (inDegree part).
  By reversing the graph.


Steps-:
1)reverse the graph.
2)calculate the inDegree of it.
3)and do same copy paste of topological sort.


Code-: Time->O(E) + O(ansLog(ans))  Space->O(V+E)
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int V=graph.size();
         vector<int>ans;

         vector<int>adj[V];    
         for(int i=0;i<V;i++)    Time Complexuty ->O(E)  no. of edges because its directed graph check how many times we are treverseing here.
         {
             for(auto x:graph[i])
             {
                 adj[x].push_back(i);
             }
         }


         vector<int>inDegree(V,0);
         for(int i=0;i<V;i++)
         {
            inDegree[i]=graph[i].size();
         }

         queue<int>q;
         for(int i=0;i<V;i++)
         {
            if(inDegree[i]==0)
            q.push(i);
         }
         
         while(q.empty()==false)
         {
             int val=q.front();
             q.pop();
             ans.push_back(val);

             for(auto x:adj[val])
             {
                inDegree[x]--;
                if(inDegree[x]==0)
                q.push(x);
             }
         }
         sort(ans.begin(),ans.end());
         return ans;
}





Solution 2-:

Intution -:
1) Here if you do dry run u can when there is a cycle that cycles node is never ever the safe nodes.
   WHY ?
   If any node is in cycle can that particular node can be my terminal node ->
   No.
   because terminal is that node why outDegree is 0.

   for eg.
   Total nodes=> 7 
   1,2,3 nodes make cycle.
   6,7 nodes are terminal nodes.
   it means these 3 nodes are not my terminal nodes.
   and they never stop at same point.

   There may be chance 2->node is reach to my terminal node (7).
   but but 
   2->node is a part of cycle means it has multiple path 
   but but.
   safe node is that node from where if we have 10 path all 10 path will be reached to terminal node.


Note-: Make a graph and apply all these information.


Steps-:
1)In question our graph is directed graph.
2)and we alreday know how to detect a cycle in a dircted graph -> using visited array and recur array.
3)here we copy paste the same code of detect cycle in a directed graph.
4)All the nodes which is part of my cycle     -> rec[i]=true.
  All the nodes which is not part of my cycle -> rec[i]=false.

5)At the end which we check all the nodes for detect cycle 
  and here we have to traverse the rec array which is false that is my 
  safe nodes.


Note -: In a question which is in terms of outgoing graphs 
        its make a cycle so pls donot modified graph in inDegree here 
        because its change the order which change the cycle as well.
        so pls do it as it given to us.

Dry run-:
[[1,2],[2,3],[5],[0],[5],[],[]]

Here -> 0->1->3->0 make a cycle.
Code-:  Time->O(V+E)  Space->O(V+E)
bool dfs(vector<int>adj[],vector<int>&visited,int src,vector<int>&rec)
    {
        visited[src]=true;
        rec[src]=true;

        for(auto x:adj[src])
        {
            if(visited[x]==false)
            {
                 if(dfs(adj,visited,x,rec))
                 return true;
            }
            else if(rec[x]==true)
            return true;
        }
        rec[src]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>adj[V];

        for(int i=0;i<V;i++)
        {
            for(auto x:graph[i])
            {
                adj[i].push_back(x);
            }
        }

        vector<int>visited(V,false);
        vector<int>rec(V,false);

        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            dfs(adj,visited,i,rec);
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(rec[i]==false)
            ans.push_back(i);
        }
        return ans;
    }