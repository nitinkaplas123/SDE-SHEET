Solution : 
Steps-:
1)same as n queen,
2)in place of adding queen board in vector of vector here we increment in count.
3)at last in place of return v of v we return count.


Code-:
bool isSafe(int row,int col,int n,vector<string>&board)
{
        int r=row;
        int c=col;

        while(r>=0 and c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            r--;
            c--;
        }

        r=row;
        c=col;
        while(c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            c--;
        }
        
        r=row;
        c=col;
        while(r<n and c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            r++;
            c--;
        }
        return true;
}

void helper(int col,int n,vector<string>&board,int &count)
{
        if(col==n)
        {
            count++;
            return ;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                helper(col+1,n,board,count);
                board[row][col]='.';
            }
        }
}
int totalNQueens(int n) {
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        int count=0;
        helper(0,n,board,count);
        return count;
}