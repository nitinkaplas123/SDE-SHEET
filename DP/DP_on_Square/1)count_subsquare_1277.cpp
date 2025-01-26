Solution 1-:
Steps-:
1)copy the same in count matrix 
  if(i==0 | j==0)
2)Now if matrix[i][j]==1
{
  [0,0]    [0,1]
  [1,0]    [1,1]
}

for (1,1) -> 1+ min(all three) 

3)now count matrix is filled add all its value in a variable ans. 
4)return ans;

Time->O(N*M) Space->O(N*M)
Code-:
int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>count(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                count[i][j]=matrix[i][j];
                else if(matrix[i][j]==1)
                count[i][j]=1+min(count[i-1][j],min(count[i-1][j-1],count[i][j-1]));
                ans+=count[i][j];
            }
        }
        return ans;
}





Solution 2-:
Steps-:
1)Space optimisation. 

Time->O(N*M)
Space->O(N+M)
Code-:
int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>prev(m,0);
        vector<int>curr(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                curr[j]=matrix[i][j];
                else if(matrix[i][j]==1)
                curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
                else
                curr[j]=0;
                ans+=curr[j];
            }
            prev=curr;
        }
        return ans;
}




Solution 3-:
Steps-:
1)More space optimisation. 
2)Here we update in matrix which we are doing in count matrix.

Time->O(N*M)
Space->O(1)
Code-:
int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0) and matrix[i][j]==1)
                ans+=1;
                else if(matrix[i][j]==1)
                {
                    matrix[i][j]=1+min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i][j-1]));
                    ans+=matrix[i][j];
                }
            }
        }
        return ans;
}