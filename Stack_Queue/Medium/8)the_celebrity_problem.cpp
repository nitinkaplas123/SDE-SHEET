Solution 1-:
Steps-:
1)using 2 for loops.
2)here if ith is the celebrity where celebrity does not known to evryone.
3)but everyone noose the celebrity.

Code-:
int celebrity(vector<vector<int> >& mat) {
       int n=mat.size();
       int res=0;
       //here if ith is the celebrity where celebrity does not known to evryone.
       for(int i=0;i<n;i++)
       {
           int count=0;
           for(int j=0;j<n;j++)
           {
               if(mat[i][j]==1)
               count++;
           }
           if(count==0)
           {
               res=i;
               break;
           }
       }
       
       //but everyone noose the celebrity except celebrity itself thats why 
       // count==n-1
       int count=0;
       for(int i=0;i<n;i++)
       {
           if(mat[i][res]==1)
           count++;
       }
       return (count==n-1)?res:-1;
}


Solution 2-:
Steps-:
1)Here we all index put into stack.
2)Now we take two index from stack.
  suppose i and j 
  if M[i][j]==1 means i know the j person which means i is not the celebrity.
  so we pop the i index from the stack.
  else
  M[i][j]==0 means i do not  know the j person so j is not celebrity.
  so we pop j from the stack.
3)At end we left with 1 index suppose its K
4)Now we check using for loop
  M[k][i]==1 means our possible person know to anyone return -1;
5)Now check if using for loop
  M[i][k]!=1 return -1;

  else
  return K th person is the celebrity.


Code-: Time->O(N) Space->O(N)
int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>=2)
        {
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(mat[first][second]==1)
            st.push(second);
            else
            st.push(first);
        }
        
        // agr element kissko janta ha return -1;
        int celeb=st.top();
       
        for(int i=0;i<n;i++)
        {
            if(mat[celeb][i]==1)
            return -1;
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mat[i][celeb]==1)
            count++;
        }
        return (count==n-1)?celeb:-1;
}


Solution 3-:
Steps-:
1)
