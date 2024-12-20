Solution 1-:

Ananlyse-:
1)Here we given the startRow and startColumn.
2)We just have to go in the form of spiral.

3)Do the dry run of spiral how its print.
  If u ananlyse the thing -:
  1)When we go to (EAST and West) direction our steps++.


Steps-:
1)

Cases -:
1)Go to right  (East direction)   (0,1)
2)Go to bottom (North direction)  (1,0)
3)Go to left   (West direction)   (0,-1)
4)Go to top    (North direction)  (-1,0)

vector<vector<int>>directions{
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

2)vector<vector<int>>ans;  
  while(ans.size()<rows*cols)
  This while loop run till we add all the indexes value here.

3)We have 4 directions so we take 
  int dir=0  (because we start from easy (right direction))
  and go all the 4 directions and then start from 0 to 3 and then 0 to 3.
  This is called as spiral matrix.

  Then your 1 direction complete then 
  dir=(dir+1)%4.

4)We start with steps=0 
  and we add 
  ans.push_back({startRow,startCol});

5)Do the dry run of spiral how its print.
  If u ananlyse the thing -:
  1)When we go to (EAST and West) direction our steps++.

  Thats why 
  if(dir==0 || dir==2) // means east and west 
  dir++;




vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<vector<int>>directions{
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        int steps=0;
        int dir=0;
        ans.push_back({rStart,cStart});
        while(ans.size()<rows*cols)
        {
            if(dir==0 || dir==2)
            steps++;

            for(int i=0;i<steps;i++)
            {
                rStart+=directions[dir][0];
                cStart+=directions[dir][1];

                if(rStart>=0 and rStart<rows and cStart>=0 and cStart<cols)
                {
                    ans.push_back({rStart,cStart});
                }
            }
            dir=(dir+1)%4;
        }
        return ans;
}



Time Complexity -:
1)Very first time we analyze its O(rows * cols)
  but its not correct 
  Because we are out of boundary again my for loops run depends upon steps 
2)Thats the reason its complxity will be O(max(rows,cols))^2.


