https://www.geeksforgeeks.org/problems/bipartite-graph/1

Case 1-:
Idea -:
1)if the graph is linear then its 100% bipartiate. -> 0 -> 1-> 0 -> 1 -> 0.

Case 2-:
1)If there is cycle in a graph ->
  1.1 -> if the no. of nodes is even -> return true. -> bipartiate.
  1.2 -> if the no. of nodes is odd -> return false. -> not a bipartiate.

Solution 1-:
Steps-:
1) Bipartite means there we have 2 types of color. -> 0 or 1.
2) Bipartite means in a given graph adjacent nodes donot have same color.

Idea -:
1) current node has 0 color then adjacent 1 then its adjacent 0 then its adjacent 0 something like that.
2) There is 2 cases -:
     color[node]=0. 
   1. if color[x]!=-1 its its not color yet. (then color with its adjacent color node).
      color[x]=!color[node].
   2. if its color[x]!=-1 means its coloured.
      color[x]==color[node]  -> means its not bipartiate. 

    
Time->O(V+E)      
Code-:
bool isBipartite(vector<vector<int>>&graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        color[0]=0;
        q.push(0);

        while(!q.empty())
        {
            int node=q.front();
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