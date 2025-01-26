Steps-:
1)Here we are running a loop of n*m where we are searching the word[0]. 
2)when we find the first charcter of word from there we are going to all 4 directions and using backtracking we are able to solve the problem.



Code-: 
Time-> O(n*m*4^L) where l is the length of the word -> in helper max we are finding the word in board so maxx we go to depth of word lenth.
                  and at each point we have 4 directions.
Space->O(N*M) for visited array.
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
bool helper(int row,int col,vector<vector<char>>& board,int n,int m,int index,string &word,int size,
                vector<vector<bool>>&visited)
{
         if(index==size)
         return true;
         visited[row][col]=true;
         for(int i=0;i<4;i++)
         {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false)
            {
                if(board[ur][uc]==word[index])
                {
                   if(helper(ur,uc,board,n,m,index+1,word,size,visited))
                   return true;
                }
            }
         }
         visited[row][col]=false;
         return false;
}

bool exist(vector<vector<char>>& board, string word) {
         int n=board.size();
         int m=board[0].size();
         char ch=word[0];
         int size=word.size();
         vector<vector<bool>>visited(n,vector<bool>(m,false));
        
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==ch)
                { 
                    if(helper(i,j,board,n,m,1,word,size,visited))
                    return true;
                }
            }
         }
         return false;
}



Solution 2-:
Steps-:
1)Space optimisation without using visited array. 

Time->same as up.
Space->O(1)  or O(length of word) bcz of recursive call stack.
Code-:
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
bool helper(int row,int col,vector<vector<char>>& board,int n,int m,int index,string &word,int size)
{
         if(index==size)
         return true;
         char ch=board[row][col];
         board[row][col]='$';
         for(int i=0;i<4;i++)
         {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m )
            {
                if(board[ur][uc]==word[index])
                {
                   if(helper(ur,uc,board,n,m,index+1,word,size))
                   return true;
                }
            }
         }
         board[row][col]=ch;
         return false;
}
bool exist(vector<vector<char>>& board, string word) {
         int n=board.size();
         int m=board[0].size();
         char ch=word[0];
         int size=word.size();
        
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==ch)
                { 
                    if(helper(i,j,board,n,m,1,word,size))
                    return true;
                }
            }
         }
         return false;
}