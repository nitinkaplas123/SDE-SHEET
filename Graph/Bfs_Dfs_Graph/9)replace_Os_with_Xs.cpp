https://www.geeksforgeeks.xorg/problems/replace-os-with-xs0052/1


Note -:
 Agar boundarys -> "O" ha tu its never make it "X".
 and  if any any point boundarys -> "O" ha then its neighbour (adjacent in all 4 direction) -> can never be change its remain "O".



Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
Means-:
1)Either replace the 'O' ->        if its adjacent of it left,right,top,bottom -> 'X'.
2)Either replace grouped of 'O' ->   


A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at 
locations just below, just above, just left and just right of it.


Intution-:
If all the boundary mat[i][j]=='O' then its adjacent left,right,top,bottom=='O' 
so we cannot make it to 'X'.


Solution 1-:
Steps-:
0)we have queue,visited[i][j]=false
1)If the boundary mat[i][j]=='O' then we push its index into queue and make its visited[i][j]=true
  which means visited[i][j]=true means its always -> 'O' we cannot change it.
2)Now we traverse the queue index in all 4 directions 
  1. its its in matrix && mat[ux][uc]='O' and visited[ux][uc]==false.
     then -> visited[ux][uc]=true ,
             q.push_back({ux,uc});

3)Now run the visited array 
  if(visited[i][j]==true)
  ans[i][j]='O';
  else
  ans[i][j]='X'

Note -:
we update the mat 2d vector from visited array.

Code-: Time->O(n*m) Space->O(n*m)
vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat)
    {
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(mat[i][j]=='O')
                    {
                         q.push({i,j});
                         visited[i][j]=true;
                    }
                }
            }
        }
        
        
        
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        while(q.empty()==false)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int ux=row+r[i];
                int uc=col+c[i];
                if(ux>=0 and ux<n and uc>=0 and uc<m and mat[ux][uc]=='O'
                   and visited[ux][uc]==false)
                {
                    q.push({ux,uc});
                    visited[ux][uc]=true;
                }
            }
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false)
                mat[i][j]='X';
                else
                mat[i][j]='O';
            }
        }
        return mat;
}

