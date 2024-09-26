https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

Solution 1-:
Steps-:
1)Same as the lcs 
2) just added in if condition when i!=j. 

int LongestRepeatingSubsequence(string str){
	    int m=str.length();
		vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str[i-1]==str[j-1] and i!=j)
                curr[j]=1+prev[j-1];
                else 
                curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return curr[m];
}