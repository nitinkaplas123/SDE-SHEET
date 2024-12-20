Solution 1-:
Steps-:
1)Using 2 for loops.

Code-: Time->O(4*N*M)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=mat[i][j]; 
                //top bottom left right 
                if((i==0 || mat[i-1][j]<val) and 
                   (i==n-1 || mat[i+1][j]<val) and 
                   (j==0 || mat[i][j-1]<val) and 
                   (j==m-1 || mat[i][j+1]<val))
                return {i,j};
            }
        }
        return {-1,-1};
}



Solution 2-:
Steps-:
1)we want the element which is greater than left,right,top,bottom.
2)so we find the largest element in matrix that is greater than all 4 sides.

Code-: Time->O(N*M)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int maxx=INT_MIN;
        int index1=-1,index2=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]>maxx)
                {
                    maxx=mat[i][j];
                    index1=i;
                    index2=j;
                }
            }
        }
        return {index1,index2};
}



Solution 3-:
Steps-:
 0  1  2  3  4
[10,50,40,30,20]
[1,500,2,3,4]

1)we do binary search from row wise 
  low=0 high=m-1
  mid=2
2)Now we have to find the maxx element in mid column which is 2 column 
  maxx element is ->40 and its index1=0 index2=2
3)we find maxx element beacause using maxx element in col we donot need to check upelement and bottom_element.
4)if maxx element is greater than left and right element then we return that indexed.
5)if left is greater than go to left side high=mid-1;
6)if right is greater than go to right side low=mid+1;

Code-: Time->nlog(m)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int low=0;
        int high=m-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            int maxx=INT_MIN;
            int index1=-1;
            int index2=-1;
            for(int i=0;i<n;i++)
            {
                if(maxx<mat[i][mid])
                {
                    maxx=mat[i][mid];
                    index1=i;
                    index2=mid;
                }
            }

            if((mid==0 || maxx>mat[index1][mid-1]) and 
               (mid==m-1 || maxx>mat[index1][mid+1]))
            return {index1,index2};
            else if(mid!=0 and maxx<mat[index1][mid-1])
            high=mid-1;
            else
            low=mid+1;
        }
        return {-1,-1};
    }

