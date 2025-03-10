Solution 1-:
Steps-:
1)make a vector nums for size 9.
2)now using the same intution which is in combiantion sum2 and subset sum2. 
3)do not create the duplictaes ->(i==index || nums[i]!=nums[i-1]).
4)ans -> (v1.size()==k and target==0) 
  store -> ans.push_back(v1);


Code-: Time->O(2^n)
void helper(vector<int>&nums,int index,int target,vector<int>&v1,vector<vector<int>>&ans,int len)
{
        if(v1.size()==len and target==0)
        {
            ans.push_back(v1);
            return;
        }    
        for(int i=index;i<9;i++)
        {
            if((i==index ||nums[i]!=nums[i-1]))
            {
                v1.push_back(nums[i]);
                helper(nums,i+1,target-nums[i],v1,ans,len);
                v1.pop_back();
            }
        }
}
vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }
        
        vector<int>v1;
        helper(nums,0,n,v1,ans,k);
        return ans;
}



Solution 2-:
Steps-:
1)without using nums array (1->9)
Time Complexity: O(C(9, k) * k)
Space Complexity: O(C(9, k) * k)

Code-:
void helper(int index,int target,vector<int>&v1,vector<vector<int>>&ans,int len)
{
        if(v1.size()==len and target==0)
        {
            ans.push_back(v1);
            return;
        }    
        for(int i=index;i<=9;i++)
        {
            if((i==index ||i!=(i-1)))
            {
                v1.push_back(i);
                helper(i+1,target-i,v1,ans,len);
                v1.pop_back();
            }
        }
}

vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v1;
        helper(1,n,v1,ans,k);
        return ans;
}