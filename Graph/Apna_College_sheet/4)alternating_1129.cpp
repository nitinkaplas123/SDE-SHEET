Refernce-:
https://www.youtube.com/watch?v=8FcdSwqR3Js



Code-:
class Solution {
public:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        
        for (auto &edge:edges) 
        {
            if(parent[edge[1]]==0)
            parent[edge[1]] = edge[0]; 
            else 
            {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
       
        for (int i = 1; i <= n; i++) 
        {
            parent[i] = i;
        }
        for (auto &edge:edges) 
        {
            if (edge[1] == 0) 
            continue;
            int u = edge[0];
            int v = edge[1];
            int pu = root(parent, u);
           
            if (pu == v)
            {
             if(candA.empty()) return edge;
             return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
};