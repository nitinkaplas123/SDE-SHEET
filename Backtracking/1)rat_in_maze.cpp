https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Note -:
In a single path we can traverse a cell only onces.

Task-:
1)we are at top left and my destination is bottom right.
2)When mat[i][j]=1 means we can traverse through it.
  mat[i][j]=0 means we cannot that cell is blocked.


Steps-:
1)we make a curr string which stores the curr path.
2)And we know that in a single path we can only traverse one cell only one time. 
  for that we are using visited array so that visited[i][j] will tell me its visited or not.
  visited[i][j]=0 means its not visited yet we can go to that cell.
  visited[i][j]=1 means its visited pls do not visited that cell again.

Case1-:
if(i<0 || i==n || j<0 || j==n) 
return ;
means u r out of bound.


Case2-:
if(mat[i][j]==0)
return;
Its block cell. 


Case3-:
if(i==n-1 and j==n-1)
{
            ans.push_back(curr);
            return ;
}
U r at destination.

Case4-:
If visited[i][j]=0
{
    make it visited[i][j]=1;
    go to 4 directions.
    after completed all the 4 directions.
    make that cell unvisited visited[i][j]=0
    bcz i need all the possible paths now its time to go backtrack and if any my parent function is not go in all 4 directions 
    they can go and make new path -> so to travel new travel we need visited[i][j]=0 na 
    bcz question said in a path u can only traverse one cell.
    but now we are finding different path.
}

Code-:
void helper(vector<vector<int>>&mat,int n,int i,int j,string curr,
                vector<vector<int>>&visited,vector<string>&ans)
{
        if(i<0 || i==n || j<0 || j==n) 
        return ;
        
        if(mat[i][j]==0)
        return;
    
        if(i==n-1 and j==n-1)
        {
            ans.push_back(curr);
            return ;
        }
        
        if(visited[i][j]==0)
        {
             visited[i][j]=1;
             helper(mat,n,i-1,j,curr+"U",visited,ans);
             helper(mat,n,i+1,j,curr+"D",visited,ans);
             helper(mat,n,i,j-1,curr+"L",visited,ans);
             helper(mat,n,i,j+1,curr+"R",visited,ans);
             visited[i][j]=0;
        }
        return;
}

vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        int n=mat.size();
        int i=0;
        int j=0;
        string curr="";
        vector<vector<int>>visited(n,vector<int>(n,0));
        helper(mat,n,i,j,curr,visited,ans);
        return ans;
}