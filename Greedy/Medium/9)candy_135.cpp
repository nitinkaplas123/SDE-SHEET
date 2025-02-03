Solution 1-:
Steps-:
1) make temp array (n,1)
eg. [1,0,2]

temp[1,1,1]

2)update the temp standing at i index and see towards the neighbour in left side.

         [1,0,2]

left->   [1,1,2]


3)update the temp standing at i index and see towards the neighbour in right side.

         [1,0,2]

right -> [2,1,1]

4)update temp[i]=max(left[i],right[i])

temp[i]=[2,1,2]

5)add all -> 2+1+2 -> 5.


Time->O(N) 
Space->O(N)
Code-:
int candy(vector<int>&nums) {
        int n=nums.size();
        vector<int>temp(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            temp[i]=max(temp[i],1+temp[i-1]);
        }

        for(int i=n-2;i>=0;i--)
        {
           if(nums[i]>nums[i+1])
           temp[i]=max(temp[i],1+temp[i+1]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
          ans+=temp[i];
        }
        return ans;
}