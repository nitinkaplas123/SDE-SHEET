Solution 1-:
Steps-:
1)tree length will be k for every case.


Time->nCk -> n!/(n-k)! * k!;
Code-:
void helper(vector<int>&nums,int index,int n,int k,vector<int>&v1,vector<vector<int>>&ans)
{
        if(k==0)
        {
            ans.push_back(v1);
            return ;
        }

        for(int i=index;i<n;i++)
        {
            v1.push_back(nums[i]);
            helper(nums,i+1,n,k-1,v1,ans);
            v1.pop_back();
        }
}
vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>ans;
       vector<int>v1;
       vector<int>nums;
       for(int i=1;i<=n;i++)
       {
          nums.push_back(i);
       }
       
       helper(nums,0,n,k,v1,ans);
       return ans;
}


Solution 2-:
Steps:
1)without making an array.

Code-:
void helper(int val,int n,int k,vector<int>&v1,vector<vector<int>>&ans)
{
        if(k==0)
        {
            ans.push_back(v1);
            return ;
        }

        for(int i=val;i<=n;i++)
        {
            v1.push_back(i);
            helper(i+1,n,k-1,v1,ans);
            v1.pop_back();
        }
}
vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>ans;
       vector<int>v1;
       helper(1,n,k,v1,ans);
       return ans;
}