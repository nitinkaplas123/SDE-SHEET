Floyd Warshal Algo-:
1)Find the shortest distance from every vertex to every vertex.
2)There is multiple source means all vertex are treated as source here.
  thats why its called as multisource shortest path algorithms.
3)Its help us to do -ve cycle as well.


Intution-:
1)find the shortest distance of u from v 
  we have to go via every vertex to calculate u to v.

  for eg. 
  having n=6 vertex.
  u=1 v=5
  i want to find the shortest distance bw 1->5 
  we have to go via every vertex which is present in graph 
  via=> 0,2,3,4,6

for eg.
1)dist[0][1] -> 0->1 + 1->1
2)dist[0][1] -> 0->2 + 2->1 
3)dist[0][1] -> 0->3 + 3->1
4)dist[0][1] -> 0->4 + 4->1
                i  k   k  j  

can we say that 
dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

eg. 
dist[0][4] => dist[0][2] + dist[2][4]
to calculate 0->4 => 0->2 + 2->4
means to calculate 0->4 we need 0->2 and 2->4
means 0->2 and 2->4 is already calculate before 0->4
means its a DP problem.



Question Explanation-:
1)Here we need adjacency matrix n*n 
2)Here at index i,j we are storing the weighted edge.
  where i->i =0 
3)In the question we already give the matrix if its not given u want to make it first.
4)question matrix gives you -1 as well, which means there is no directed link between i->j.


Steps-:
1)First where there is no edges means mat[i][j]=-1 make it mat[i][j]=INT_MAX so that for the corresponding vertex we can fill the min value there.
2)Now calculate the shortest distance from i->j via all vertex using k.
3)At last  where there is INT_MAX we have to add -1 there.

Code-: Time->O(N^3)
void shortest_distance(vector<vector<int>>&matrix)
{
	    int n=matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	        }
	    }
	    for(int k=0;k<n;k++)
	    {
	       for(int i=0;i<n;i++)
	       {
	         for(int j=0;j<n;j++)
	         {
	            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	         }
	       }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	           if(matrix[i][j]==1e9)
	           matrix[i][j]=-1;
	        }
	    }
}