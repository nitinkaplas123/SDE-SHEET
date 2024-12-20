https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums

Steps-:
1)here we need sum of all subsets.

Code-:
void helper(vector<int>&arr,int index,int n,int sum,vector<int>&ans)
{
        if(index==n)
        {
            ans.push_back(sum);
            return ;
        }
        
        helper(arr,index+1,n,sum,ans);
        helper(arr,index+1,n,sum+arr[index],ans);
}
vector<int> subsetSums(vector<int>& arr) {
      int n=arr.size();
      vector<int>ans;
      int sum=0;
      helper(arr,0,n,sum,ans);
      return ans;
}