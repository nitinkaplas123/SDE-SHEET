https://www.youtube.com/watch?v=Gl-8HLvV8bc
Solution 1-:
Steps-:
Case1-:
when nums[j]==1 
{
  simply store the ans=max(ans,j-i+1);
  j++;
}


Case2-:
when nums[j]==0
{
   Case1-:
   if we have k there 
   {
     k--; // use the k for j position 
     j++;
   }
   Case2-:
   we dont have k now we have to shrink the window from the start means from i 
   we need from start nums[i]=0 
   {
      we find nums[i]==1 
      while(nums[i]==1)
      i++;

      // when we find the first nums[i]=0 means we dont want to add in our current window.
      // do one time i++;
      i++;
   }
}



Code-: Time->O(2*n) Space->O(1)
int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n)
        {
            if(nums[j]==0)
            { 
                if(k!=0)
                k--;
                else
                {
                    while(nums[i]==1)
                    {
                        i++;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
}