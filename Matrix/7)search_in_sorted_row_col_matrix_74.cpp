Solution 1-:
Steps-:
1)here we travserse all matrix in row and col wise.

Code-: Time->O(n*m) Space->O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(matrix[i][j]==target)
               return 1;
            }
        }
        return 0;
}


Solution 2-:
Steps-:
1)Here first we find the possible row which are target will be there.
2)Now when we have row now traverse its whole row.
3)If target in that row present then return 1 else return 0;

Code-: Time->O(n+m) Space->O(1)
int helper(vector<vector<int>>& matrix,int target,int n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<=target)
            {
                ans=i;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=helper(matrix,target,n);
        for(int i=0;i<m;i++)
        {
            if(matrix[row][i]==target)
            return 1;
        }
        return 0;
    }



Solution 3-:
Steps-:
1)Here first we have to find the row here we know our row is sorted so we use binary search to find it.
2)When we find the row now on that row we find matrix[row][i] using again binary search.

Code-: Time->O(log(n) * O(log(m))  Space->O(1)
 int helper(vector<vector<int>>& matrix,int target,int n)
    {
        int ans=0;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid][0]<=target)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=helper(matrix,target,n);
        
        int low=0;
        int high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[row][mid]==target)
            return 1;
            else  if(matrix[row][mid]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return 0;
    }


Solution 4-:
Steps-:
1)Convert 2D matrix into 1D hypothetically. 
2)apply binary search 

Code-: Time->O(log(m*n)) Space->O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int low=0;
        int high=n*m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
            return true;
            else if(matrix[row][col]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return false;
}