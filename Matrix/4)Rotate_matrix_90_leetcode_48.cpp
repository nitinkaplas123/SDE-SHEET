Solution1-:
1)Just visualize the pattern and  store into dummy vector of vcetor.
 
Code-:  Time Complexity->O(n*n)   Space ->O(n*n)
void rotate(vector<vector<int>>& matrix) {
         int n=matrix.size();
         vector<vector<int>>mat(n,vector<int>(n));
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<n;j++)
            {
                mat[j][n-1-i]=matrix[i][j];
            }
         }
         matrix=mat;
}



Solution 2-:   Time->O(n*n)    Space ->O(1)

Steps-:
1)By clearly visualizing 
2) First we have to transpose the given matrix
3)Then reverse every row 
4)At last we achive our goal


Code-:

void transpose(vector<vector<int>>&matrix)
{
      int n=matrix.size();
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
           swap(matrix[i][j],matrix[j][i]);
        }
     }
}
void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose
        transpose(matrix);
        
        //reverse every row
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
}




