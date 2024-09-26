
N queens -: 
1)Means we have a n*n chess board.
2)We have to place a n queen in a chess board in such a way that no two queens are attack each other.

Attack -:
1)one queen attack in its 8 directions.
  1. up 
  2. down
  3. left.
  4. right
  5. diagonal top.
  6. diagonal down
  7. anti diagonal top.
  8. anti diagonal down.


  Steps or conditions
  1)In each row we have 1 queen.
  2)In each column we have 1 queen.
  3)No two queens attack each other.


Steps-:
1)We start filling first column where 
  solve(0) as column.

Solve()
1)if my col==n means out of bound 
  ans.push_back(board) -> we go our first answer.
2)right now we are at some column -> now we have n rows where we want to fit. 
  this part will be ask from (isSafe) function.

case1-:
if(isSafe)
board[row][col]='Q';
go to next column  -> (col+1);
again we have n rows.

same steps....

Case2-: 
if we are checked all 4 rows and we are not able to fit it at any row in that case we have to backtrack means 
board[row][col] is not the correct options.
make it board[row][col]='.'


SO ON.....


isSafe() function 
here we can go 8 directions but we only have to ask from 3 direction because rest are not fill it yet.
1.     [row-1][col-1]
2.     [row][col-1]        [row][col]
3.     [row+1][col-1]

note -:
if any point if board[row][col]=='Q' is there means they attack each other means they are not safe.
return false.


Code-:
bool isSafe(int row,int col,int n,vector<string>&board)
{
        int dupRow=row;
        int dupCol=col;

        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            row--;
            col--;
        }
        
        row=dupRow;
        col=dupCol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            col--;
        }

        row=dupRow;
        col=dupCol;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            row++;
            col--;
        }
        return true;

}

void solve(int col, vector<string>&board,vector<vector<string>>&ans,int n)
{
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
        return ;
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
}