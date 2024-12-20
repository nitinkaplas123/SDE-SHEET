Steps-:
1)Here we do the backtracking -> 
if we pick it 
  1. adding into v1
  2. calling the function 
  3. after completing the function its pop_back the value from the v1. 

if not 
helper(nums,index+1,n,target,v1,s);

2) base case -:
if target==0 
add v1 into set. 

3)we use set here for all the unique vectors  


Time Complexity -> 
O(2^n)               all geneate all subset 
O(2^n log(2^n))   -> in worst case we are adding all subset in set and in set we make it as in sorted order. 


Time complexity ->O(2^n * (klog(size of set )) 
where k is no. of times vector to add into set 


Code-: 
void helper(vector<int>&nums,int index,int n,int target,vector<int>&v1,set<vector<int>>&s)
{
         if(index==n)
         {
            if(target==0)
            s.insert(v1);
            return ;
         }
         //not pick 
         helper(nums,index+1,n,target,v1,s);

         if(target>=nums[index])
         {
            v1.push_back(nums[index]);
            helper(nums,index+1,n,target-nums[index],v1,s);
            v1.pop_back();
         }
}

vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v1;
        int index=0;
        set<vector<int>>s;
        helper(nums,index,n,target,v1,s);
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
}




Solution 2-:
Steps-:
1)to avoid duplicates first we sort the array. 
2)below digram i say we can start it or not 
  two conditions 
  
                                       
                                       index=0 
                                     [1,1,1,2,2]
                              
              index=0,i=0,       index=0,i=1                                     index=0,i=2                                  index=0,i=3,target>=nums[i]    index=0,i=4,target>=nums[i]
                                 but nums[i]==nums[i-1] for duplicate            but nums[i]==nums[i-1] for duplicate                                        but nums[i]==nums[i-1] for duplicate  
                [1]              ignore it                                       ignore it                                     [2]                      


3)pls see striver video first 10mins 
https://www.youtube.com/watch?v=G1fRTGRxXU8&t=695s

Case 1-:
when (target==0)
{
    ans.push_back(v1);
    return ;
}

Case2-:
if((i==index) && target>=nums[i])
means its new level of deeping tree.  (or we can say going vertically left side) here always i==index
add the v1.push_back(nums[i])

Case3-:
if((nums[i]!=nums[i-1]) && target>=nums[i])
means if its going horizontally then for duplicates check nums[i]!=nums[i-1] and target>=num[i]
add the v1.push_back(nums[i])

Code-: Time->O(2^n) because at each element we have 2 options take it or do not take it
                    due to which we have 2^n possible subset 
void helper(vector<int>&nums,int index,int n,int target,vector<int>&v1,vector<vector<int>>&ans)
{
         if(target==0)
         {
            ans.push_back(v1);
            return;
         }
    
         for(int i=index;i<n;i++)
         {
            if((i==index || nums[i]!=nums[i-1]) and target>=nums[i])
            {
                v1.push_back(nums[i]);
                helper(nums,i+1,n,target-nums[i],v1,ans);
                v1.pop_back();
            }
         }
}

vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v1;
        sort(nums.begin(),nums.end());
        helper(nums,0,n,target,v1,ans);
        return ans;
}