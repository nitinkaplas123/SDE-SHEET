Solution 1-:
Steps-:
1)using idea of count subsqaure.
2)use the same appraoch where we fill count 2d array where at position i,j we fill how many sqaure we can make at a given index.
3)Now at every index we have to find the max no. of sqaure that grid index contribute.
  for eg. at any position we have count[i][j]=2.
  it means it create 1*1 and 2*2 square -> so here we have maxx sqaure area is 4. 

  similarily at any grid index if we have count[i][j]=3.
  it means 
  it create 
  1*1, 2*2, 3*3 
  so here 9 is the maxx area.
4)so idea is to store the max no. of squares we can make.
5)At the end just do the sqaure of that number.


Time ->O(N^2)
Space->O(N^2)
Code-:
int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxx=0;
        vector<vector<int>>count(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(i==0 || j==0) 
               count[i][j]=(matrix[i][j]-'0');
               else if(matrix[i][j]=='1')
               count[i][j]=1+min(count[i-1][j],min(count[i-1][j-1],count[i][j-1]));
               else
               count[i][j]=matrix[i][j]-'0';
               maxx=max(maxx,count[i][j]);
            }
        }
        return maxx*maxx;
}




Solution 2-:
Steps-:
1)Same as optimised we did it count subsquares.

Time ->O(N*M)
Space->O(M)
Code-:
int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>prev(m);
        vector<int>curr(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(i==0 || j==0)
               curr[j]=matrix[i][j]-'0';
               else if(matrix[i][j]=='1')
               curr[j]=(1+min(prev[j],min(prev[j-1],curr[j-1])));
               else
               curr[j]=matrix[i][j]-'0';
               ans=max(ans,(curr[j]));
            }
            prev=curr;
        }
        return ans*ans;
}