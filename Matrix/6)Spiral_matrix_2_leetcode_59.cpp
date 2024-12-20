vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans( n , vector<int> (n));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int val=1;
        while(top<=bottom && left<=right)
        {
            //left to right
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=val++;
                // ans.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top;i<=bottom;i++)
            {
                ans[i][right]=val++;
              //  ans.push_back(matrix[i][right]);
            }
            right--;

            //right to left
            if(top<=bottom)
            {
               for(int i=right;i>=left;i--)
               {
                ans[bottom][i]=val++;
                //ans.push_back(matrix[bottom][i]);
               }
               bottom--;
            }
            

            //bottom to top
            if(left<=right)
            {
              for(int i=bottom;i>=top;i--)
              {
                ans[i][left]=val++;
                //ans.push_back(matrix[i][left]);
              }
              left++;
            }
        }
        return ans;
    }