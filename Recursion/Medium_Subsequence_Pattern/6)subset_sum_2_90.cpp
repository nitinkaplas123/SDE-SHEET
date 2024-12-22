Solution 1-:
Steps-:
1) pick + not pick 
2) for duplicate -:
   1. we sort the array first. 
   2. and we are using set of vectors.


Code-: Time->O(2^n * klog(size of set))
void helper(vector<int>&nums,int index,int n,vector<int>&v1,set<vector<int>>&s)
{
         if(index==n)
         {
            s.insert(v1);
            return ;
         }
         //not pick 
         helper(nums,index+1,n,v1,s);

         //pick 
         v1.push_back(nums[index]);
         helper(nums,index+1,n,v1,s);
         v1.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v1;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        helper(nums,0,n,v1,s);
   
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
}



Solution 2-:
Steps-:
1)same idea as for combination sum!!
2) we use v1 vector with take care of duplicates 
   if(i==index || nums[i]!=nums[i-1]) -> using this we take care of duplicates
[1,2,2]
0->size v1 -> {}
1->size v1 -> {1},{2}
2->size v1 -> {1,2},{1,3}
3->size v1 -> {1,2,2}

Reference -> https://www.youtube.com/watch?v=RIn3gOkbhQE

Code-:
void helper(vector<int>&nums,int index,int n,vector<int>&v1,vector<vector<int>>&ans)
{
        ans.push_back(v1);

        for(int i=index;i<n;i++)
        {
            if(i==index || nums[i]!=nums[i-1])
            {
                v1.push_back(nums[i]);
                helper(nums,i+1,n,v1,ans);
                v1.pop_back();
            }
        }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v1;
        sort(nums.begin(),nums.end());
        int index=0;
        helper(nums,index,n,v1,ans);
        return ans;
}