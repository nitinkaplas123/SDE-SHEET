Question-:
1)here we are given row=sr and col=sc that is the point which value we have to change to color.
2)now your task to make all the adjacent value (image[][])==color 
  if image[][]==starting 

Point-: if(image[i][j]=starting)
        image[i][j]=color; 
3)Update this image 2D array and return to me.


Solution 1-: (Using BFS)
Steps-:
CASE1-:
if(starting==color) return image;

why?
if(image[sr][sc]==starting) image[sr][sc]=color
but here starting=color // so no change.

Case2-: 
starting!=color
Steps-:
1)Make a queue for adding (row,col) index into it 
  and image[sr][sc]=color
2)Now go all index k 4 direction and do normal BFS.

        
Code-:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
        int n=image.size();
        int m=image[0].size();

        queue<pair<int,int>>q;

        int starting=image[sr][sc];
        //if(image[sr][sc]==starting) image[sr][sc]=color
        //but here starting=color // so no change.
        if(starting==color) return image;
        
        q.push({sr,sc});
        image[sr][sc]=color;

        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};

        while(q.empty()==false)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int ur=row+r[i];
                int uc=col+c[i];

                if(ur>=0 and ur<n and uc>=0 and uc<m and image[ur][uc]==starting)
                {
                    q.push({ur,uc});
                    image[ur][uc]=color;
                }
            }
        }
        return image;
}


Solution 2-: (Using DFS)

Code-:
int r[4]={-1,1,0,0};
int c[4]={0,0,-1,1};
void dfs(vector<vector<int>>& image,vector<vector<bool>>&visited,int row,int col,
             int n,int m,int starting,int color)
{
        visited[row][col]=true;
        image[row][col]=color;
        
        for(int i=0;i<4;i++)
        {
            int ur=row+r[i];
            int uc=col+c[i];
            if(ur>=0 and ur<n and uc>=0 and uc<m and visited[ur][uc]==false 
               and image[ur][uc]==starting)
            {
                visited[ur][uc]=true;
                image[ur][uc]=color;
                dfs(image,visited,ur,uc,n,m,starting,color);
            }
        }
        return ;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int starting=image[sr][sc];
        if(starting==color) return image;

        dfs(image,visited,sr,sc,n,m,starting,color);
        return image;
}


