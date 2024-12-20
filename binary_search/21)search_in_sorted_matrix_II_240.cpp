Solution 1-:
Steps-:
1)using 2 for loops.



Solution 2-:
Steps-:
1)here we know that matrix row is sorted so here we traverse n rows but at 
  every row as its sorted we use binary search.

Code-: Time->O(Nlog(M))
bool helper(vector<int>&v,int target,int m)
{
        int low=0;
        int high=m-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]==target)
            return 1;
            else if(v[mid]>target)
            high=mid-1;
            else
            low=mid+1;
        }
        return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
           if(helper(matrix[i],target,m))
           return 1;
        }
        return 0;
}



Solution 3-:
Steps-:
[1,4,7,11,15]
[2,5,8,12,19]
[3,6,9,16,22]
[10,13,14,17,24]
[18,21,23,26,30]     target=14 

Idea-:
1. we have to eleminate the row and col.
2. for that we have to choose a position which is increase and decrease in left side and down side.
3. that position is row=0 col=m-1 
4. at 15 first row last value of column.

Dry run -:
1. we at 15 (row=0 col=4)
here 15>14 which means all values in col=4 is greater than 15 as its in sorted order 
so we ignore this (col--)

2. we at 11 (row=0 col=3)
here 11<14 which means all values left side of 11 is smaller than 11 so this side our target is not.
so we ignore this side row++

3. we at 12 (row=1 col=3)
here 12<14 (row++)

4. we at 16 (row=2 col=3)
  here 16>14 col--

5. we at 9 (row=2 col=2)
   9<14 (row++)

6. we at 14 which is matched 
  return true.
 
Code-: Time->O(N+M) Space->O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int row=0;
        int col=m-1;

        while(row<n and col>=0)
        {
            if(matrix[row][col]==target)
            return true;
            else if(matrix[row][col]>target)
            col--;
            else
            row++;
        }
        return false;
    }
