Solution 1-:
Steps-:

00  01  02 
10  11  12
20  21  22

see the addition of indexes is same in diagoanl format.
1) first,third,fiveth,seventh,nineth, => odd time reverse the whole vector. 

Code-: Time->O(N*M(log(N+M))) Space->O(M)
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m1=mat[0].size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m1;j++)
            {
                int index=i+j;
                m[index].push_back(mat[i][j]);
            }
        }
        
        vector<int>ans;
        bool flag=true;
        
        for(auto x:m)
        {
           if(flag==true)
           reverse(x.second.begin(),x.second.end());

           for(auto y:x.second)
           {
              ans.push_back(y);
           }
           flag=!flag;
        }
        return ans;
    }


