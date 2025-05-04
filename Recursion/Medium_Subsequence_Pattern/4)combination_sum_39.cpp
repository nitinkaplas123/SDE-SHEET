Solution 1-:
Steps-:
1) using picking + not picking 

Code-: Time->O(2^n * nlog(n)) -> 2^n for making all subsets + nlog(n) for putting it into set. 
void helper(vector<int>&nums,int target,int index,int n,vector<int>v1,set<vector<int>>&s)
{
         if(index==n)
         {
             if(target==0)
             s.insert(v1);
             return ;
         }
         helper(nums,target,index+1,n,v1,s);
         if(nums[index]<=target)
         {
              v1.push_back(nums[index]);
              helper(nums,target-nums[index],index,n,v1,s);
         }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        int n=candidates.size();
        set<vector<int>>s;
        vector<int>v1;
        int index=0;
        helper(candidates,target,index,n,v1,s);

        for(auto x:s)
        {
            v.push_back(x);
        }
        return v;
}


or different code -:
Code-:
void helper(vector<int>&nums,int index,int n,int target,vector<int>v1,set<vector<int>>&s)
{
         if(target<0) return ;
         if(index==n)
         {
            if(target==0)
            s.insert(v1);
            return ;
         }
         helper(nums,index+1,n,target,v1,s);
         
         v1.push_back(nums[index]);
         helper(nums,index,n,target-nums[index],v1,s);
}

vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        int n=nums.size();
        vector<int>v1;
        helper(nums,0,n,target,v1,s);
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
}






Solution 2-:
Steps-:
1)Without set 

Code-: Time->O(2^n)
void helper(vector<int>&nums,int target,int index,int n,vector<int>v1,vector<vector<int>>&v)
{
         if(index==n)
         {
             if(target==0)
             v.push_back(v1);
             return ;
         }
         helper(nums,target,index+1,n,v1,v);
         if(nums[index]<=target)
         {
              v1.push_back(nums[index]);
              helper(nums,target-nums[index],index,n,v1,v);
         }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        int n=candidates.size();
        
        vector<int>v1;
        int index=0;
        helper(candidates,target,index,n,v1,v);

        return v;
}



Solution 3-:
Steps-:
1)using pass by reference -:

Code-: Time->O(2^n * k) where k is the no. of vectors which we add into ans
void helper(vector<int>&nums,int index,int n,int target,vector<int>&v1,vector<vector<int>>&ans)
{
        if(index==n)
        {
            if(target==0)
            ans.push_back(v1);
            return ;
        }
        helper(nums,index+1,n,target,v1,ans);
        if(target>=nums[index])
        {
            v1.push_back(nums[index]);
            helper(nums,index,n,target-nums[index],v1,ans);
            v1.pop_back();
        }
}

vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        vector<vector<int>>ans;
        vector<int>v1;
        int n=nums.size();
        int index=0;
        helper(nums,index,n,target,v1,ans);
        return ans;
}



Solution 4:
Pruning 


Code:
class Solution {
public:
    void backtrack(vector<int>& nums, int target, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (target == 0) 
        {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); ++i) 
        {
            if(nums[i] > target) break; 

            curr.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, curr, result); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Enables pruning
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(nums, target, 0, curr, result);
        return result;
    }
};