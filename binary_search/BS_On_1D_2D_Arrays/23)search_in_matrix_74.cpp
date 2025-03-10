Solution 0-:
Code-:
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
       int n = matrix.length;
        int m = matrix[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
}


Solution 0:

Code-:
class Solution {
     private int helper(int[][] matrix, int n, int target) {
        int low = 0;
        int high = n - 1;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    public boolean searchMatrix(int[][] matrix, int target) {
       int n = matrix.length;
        int m = matrix[0].length;

        int row = helper(matrix, n, target);

        for (int i = 0; i < m; i++) {
            if (matrix[row][i] == target) {
                return true;
            }
        }
        return false;
    }
}



Solution 1-:
Steps-:
1)Search row 
2)Search row col.


Time->O(log(n)*log(m))
Space->O(1)
Code:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=n-1;
        int row=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid][0]>target)
            high=mid-1;
            else
            {
              row=mid;
              low=mid+1;
            } 
        }
        if(row==-1) return false;
        
        low=0;
        high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[row][mid]==target)
            return true;
            else if(matrix[row][mid]>target)
            high=mid-1;
            else
            low=mid+1;
        }
        return false;
}




Soolution 2-:
Steps-:
1)hypothetical 2d arrays into 1d array,


Time->O(log(n*m))
Space->O(1)
Code-:
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


