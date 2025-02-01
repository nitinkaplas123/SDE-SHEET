https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

Solution 1-:
Steps-:
1)using recursion

Code-:
int helper(vector<int>&arr,int n,int target)
{
        if(n==0)
        {
            if(target==0) return 1;
            else return 0;
        }
        if(target>=arr[n-1])
        return helper(arr,n-1,target-arr[n-1]) + helper(arr,n-1,target);
        else
        return helper(arr,n-1,target);
}
int countPartitions(vector<int>& arr, int d) {
        int n=arr.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        
        return helper(arr,n,target);
}


Solution 2-:
Steps-:
1)using memo 

int helper(vector<vector<int>>&memo,vector<int>&arr,int n,int target)
{
        if(n==0)
        {
            if(target==0) return 1;
            else return 0;
        }
        if(memo[n][target]!=-1) return memo[n][target];
        if(target>=arr[n-1])
        return memo[n][target]=helper(memo,arr,n-1,target-arr[n-1]) + helper(memo,arr,n-1,target);
        else
        return memo[n][target]=helper(memo,arr,n-1,target);
}
int countPartitions(vector<int>& arr, int d) {
        int n=arr.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum+d)%2!=0) return 0;
        int target=(sum+d)/2;
        vector<vector<int>>memo(n+1,vector<int>(target+1,-1));
        return helper(memo,arr,n,target);
}