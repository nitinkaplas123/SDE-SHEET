Solution 1-:
Steps-:
1)Same as m colouring problem 

Time-> O(4^n) -> there are n elements and each elenent we have 4 choices of flower
Space -> O(n+E) -> n for recursive call + vector size of n + E for adj list.

Code-:
bool isSafe(int node,int number, vector<vector<int>> &adj,vector<int>&color)
{
        for(auto x:adj[node])
        {
            if(color[x]==number)
            return false;
        }
        return true;
}
bool helper(int node, vector<vector<int>> &adj,int n,vector<int>&color)
{
         if(node==n)
         return true;
         for(int i=1;i<=4;i++)
         {
             if(isSafe(node,i,adj,color))
             {
                color[node]=i;
                if(helper(node+1,adj,n,color))
                return true;
                color[node]=0;
             }
         }
         return false;
}
vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans;
        int val=n;
        vector<vector<int>> adj(n);
        
        for(int i=0;i<paths.size();i++)
        {
           int u=paths[i][0]-1;
           int v=paths[i][1]-1;
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        vector<int>color(n,0);
        helper(0,adj,n,color);
        return color;
}