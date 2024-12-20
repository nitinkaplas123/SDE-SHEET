Reference -:
https://www.youtube.com/watch?v=7zmgQSJghpo

Question -:
https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0


Steps-:
1) Suppose 
        {0,1}
     
{1,0}   {1,1} -> {1,2}

        {2,1}

Here {1,1} is the base we make string in str for one island and put into a unordered_set<string>s; 




2)Rest if needed pls read onces about the question from videos first 10mins striver explain it really well. 


Code-: Time->O(n*m) space->O(1)
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
    
void dfs(vector<vector<int>>& grid,int br,int bc,int row,int col,int n,int m,string &str)
{
        int dr=br-row;
        int dc=bc-col;
        str+=to_string(dr);
        str+=to_string(dc);
       
        grid[row][col]=2;
        
        for(int i=0;i<4;i++)
        {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and grid[ur][uc]==1)
            {
                dfs(grid,br,bc,ur,uc,n,m,str);
            }
        }
}

int countDistinctIslands(vector<vector<int>>& grid) 
{
       int n=grid.size();
       int m=grid[0].size();
       unordered_set<string>s;
       string str;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1)
               {
                   str="";
                   int br=i;
                   int bc=j;
                   dfs(grid,br,bc,i,j,n,m,str);
                   s.insert(str);
               }
           }
       }
       return s.size();
}