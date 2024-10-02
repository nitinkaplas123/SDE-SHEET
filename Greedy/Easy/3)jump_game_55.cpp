Solution 1-:
Steps-:
1)here we find the max_reach at every point.
2)If max_reach==i then it cannot reach to the last element of the array.

Dry run-:
[0,2,3]    
 
Code-: Time->O(N) Space->O(1)
bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 1;
        
        int max_reach=0;
        for(int i=0;i<n-1;i++)
        {
           max_reach=max(max_reach,i+nums[i]);
           if(max_reach==i) return 0;
        }
        return 1;
}