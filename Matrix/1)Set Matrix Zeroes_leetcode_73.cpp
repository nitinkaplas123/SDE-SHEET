Reference -:
https://www.youtube.com/watch?v=M65xBewcqcI

Note->For 3rd solution referernce Notebook 1 page -31o
Solution 1 -:   
Steps-:
1) Make a pair of vectors where we store the pair in i and j format which having value 0 (matrix[i][j]=0)
2) Now run a loop for size of vector and take x=v[i].first and y=v[i].second
3) In step 2 run a whole loop and make whole row =0 and column =0 using x and y value

Code-: Time Complexity -O(N*M)   Space ->O(N*M)
void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                v.push_back({i,j});
            }
        }

        for(int i=0;i<v.size();i++)
        { 
            int x=v[i].first;
            int y=v[i].second;
            
            for(int i=0;i<m;i++)
            matrix[x][i]=0;

            for(int i=0;i<n;i++)
            matrix[i][y]=0;
        }
    }



Solution 2-: Time complexity ->O(n*m)   space  ->O(n+m)

Steps-:
1) Make a two dummy vector row and col of size n and m and intilaise it  value as -1;
2) Traverse the matrix if matrix[i][j] =0 then row[i]=0 and col[j]=0;
3)Now Traverse the matrix again if row==0 || col==0 then make matrix[i][j]=0

Code-:
void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,-1);
        vector<int>col(m,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(row[i]!=0)
                    row[i]=0;
                    if(col[j]!=0)
                    col[j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((row[i]==0 || col[j]==0) and matrix[i][j]!=0)
                matrix[i][j]=0;
            }
        }  
    }


Solution 3 ->Time ->O(n*m) space =>O(1)

STeps-:
1)By making dummy array row and col as zero row and zero col 
2)Make bool col=true
3)This col is a variable which means if matrix[i][0]=0 means if first col value is 0 then make col=false
4)Now we are update the end points or say dummy row and col updates 
5)Now run the loop from i=n-1 to i=0 and j=m-1 to j=1 
6)When j=m-1 to j=1 update successfully then the j=0 value depend upon the col==false then make j=0 matrx[i][j]=0



Code-:
void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j==0) flag=false;
                    else 
                    {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
            }
            if(flag==false)
            matrix[i][0]=0;
        }
}