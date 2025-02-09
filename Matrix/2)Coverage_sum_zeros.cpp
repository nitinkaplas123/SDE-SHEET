question -:
https://practice.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Solution ->Time Complexiy ->O(N*M)   Space ->O(1)

Steps-:
1)Run the whole matrix
2)Add sum to whole 4 directions while mataining the corner cases 


Code-:
int FindCoverage(vector<vector<int>>&matrix){
       int n=matrix.size();
       int m=matrix[0].size();
       int sum=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(matrix[i][j]==0)
               {
                  //top
                  if(i>0)
                  sum+=matrix[i-1][j];
                  //bottom
                  if(i<n-1)
                  sum+=matrix[i+1][j];
                  //left
                  if(j>0)
                  sum+=matrix[i][j-1];
                  //right
                  if(j<m-1)
                  sum+=matrix[i][j+1];
               }
           }
       }
       return sum;
}


or 
Same logic-:
int findCoverage(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<4;k++)
                    {
                        int ur=i+r[k];
                        int uc=j+c[k];
                        
                        if(ur>=0 and ur<n and uc>=0 and uc<m and matrix[ur][uc]==1)
                        count++;
                    }
                }
            }
        }
        return count;
}