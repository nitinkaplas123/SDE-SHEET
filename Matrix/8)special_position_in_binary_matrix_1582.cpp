Solution 1-:
Steps-:
1)storing all the pair of i,j in vector of pair.
2)now traverse the indexed storing in vector and check if count of whole row and whole col (count==2) means.
  this  is the special position 

Code-: Time->O(N*M) Space->O(N*M)
int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                v.push_back({i,j});
            }
        }

        int ans=0;
        for(auto x:v)
        {
            int count=0;
            int row=x.first;
            int col=x.second;
            for(int i=0;i<m;i++)
            {
                if(mat[row][i]==1)
                count++;
            }
            for(int i=0;i<n;i++)
            {
                if(mat[i][col]==1)
                count++;
            }
            if(count==2)
            ans++;
        }
        return ans;
    }




Solution 2-:
Steps-:
1)Here we use 2 vector rows and col of size n,m.
2)here we have to traverse the whole matrix if we find value=1 then we have to increment the count in row and column.
  index.

3)Now again we traverse the matrix if (matrix[i][j]==1 and if row[i]==1 and col[j]==1) ans++; which is special position.
  which means rest all value in row and col is zero.


Code-: Time->O(N*M) Space->O(N+M)
int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>row(n,0);
        vector<int>col(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    row[i]+=1;
                    col[j]+=1;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    if(row[i]==1 and col[j]==1)
                    ans++;
                }
            }
        }
        return ans;
    }