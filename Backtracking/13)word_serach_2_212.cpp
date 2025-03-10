Solution 1-:
Steps-:
1)using word search 1 idea.

Code-:
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
bool dfs(vector<vector<char>>& board,int row,int col,int index,string word,int size,int n,int m)
{
        if(index==size)
        return true;
        char original=board[row][col];
        board[row][col]='$';

        for(int i=0;i<4;i++)
        {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and board[ur][uc]!='$' and board[ur][uc]==word[index])
            {
                if(dfs(board,ur,uc,index+1,word,size,n,m))
                return true;
            }
        }
        board[row][col]=original;
        return false;
}

string helper(vector<vector<char>>& board,string &word,int n,int m)
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,i,j,1,word,word.size(),n,m))
                    return word;
                }  
            }
        }
        return "";
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>dup(n,vector<char>(m));
        for(int k=0;k<words.size();k++)
        {
            dup=board;
            string str=helper(dup,words[k],n,m);
            if(str!="")
            ans.push_back(words[k]);
        }
        return ans;
}