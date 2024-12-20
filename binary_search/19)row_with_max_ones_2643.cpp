Solution 1-:
Steps-:
1)As rows are not sorted so we can solve this sol. brute forcely only.

Code-: Time->O(N*M) Space->O(1)
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
	    int index=0;
	    for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                count++;
            }
            if(ans<count)
            {
                ans=count;
                index=i;
            }
        }
        return {index,ans};
    }