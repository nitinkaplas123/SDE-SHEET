Approach for this Problem:

Intution -:
1)Burn a binary tree in min seconds.

Case1-:
1)If we are able to make it return minimum -> steps

Case2-:
1)If we are not able to make the fresh oranges to rotten -> return -1;

Case3-:
1)If its already all rotten oranges and (grid[i][j]=0 || grid[i][j]=2) means no one is fresh -> return 0;


Steps-:
1)Make a queue where i am storing the (indexes) of grid where grid[i][j]=2;
2)Count how many oranges are fresh in -> freshOranges. 
3)The size of indexes present in queue means using that size we can make all of its 4 directions grid element rotten so its consider to be 1 sec.
if(grid[row][col]==1)
{
    grid[row][col]=2;
    freshOranges--;
    flag=true;
    q.push({row,col});
}

when its freshOrange 
1)Make it rotten 
2)means we are at fresh now -> rotten oranges -> now its decrease by 1.
3)means in current second -> we are changing the fresh -> rotten.
4)push that indexes into q so that in future we can make all grid rotten.


Time->O(N*M)
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int freshOranges=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
                if(grid[i][j]==1)
                freshOranges++;
            }
        }

        if(freshOranges==0) return 0;
        
        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};

        int count=0;
        while(q.empty()==false)
        {
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++)
            {
               auto x=q.front();
               q.pop();
               for(int i=0;i<4;i++)
               {
                 int row=x.first+ r[i];
                 int col=x.second+ c[i];

                 if(row<0 || row==n || col<0 || col==m)
                 continue;

                 if(grid[row][col]==1)
                 {
                    grid[row][col]=2;
                    freshOranges--;
                    flag=true;
                    q.push({row,col});
                 }
               }
            }
            if(flag==true)
            count++;
        }
        return (freshOranges==0)?count:-1;
}

Note -:
return (freshOranges==0)?count:-1;
means -> at last if we are able to convert all the freshorange to rotten in that case freshOranges=0 
         which means we are succesfully convert all the freshOranges to Rotten oranges.