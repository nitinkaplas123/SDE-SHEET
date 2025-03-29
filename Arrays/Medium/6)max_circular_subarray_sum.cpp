Solution 1-:
Steps-:
1)Here we traverse two loops where we find all possible subarray.
2)In all possible subarray we have to find the max of it.

Code-:  Time->O(n2)  Space ->O(1)
int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
           int sum=0;
           for(int j=i;j<n+i;j++)
           {
              int index=(j%n);
              sum+=nums[index];
              maxx=max(maxx,sum);
           }
        }
        return maxx;
}


Solution 2 -:
Steps-:
1)Here we have to use kadane algo for normal subarray max sum.
2)Now for circular part we use a trick instead of finding max subarray we find-:
  whole sum-minimum subarray

  eg. [5,-3,5]
Step1 [5,2,7]   maxx =>7 
Step2 here min subarray is -3 and sum is 7 
      so 
      sum-minsubarray
      7-(-3) =>10 

so here max (step1,step2) 
        max(7,10) 
        =>10

3)Note here its a case when whole array is of negative value in that case normal kadane algo give us max
  subarray sum value from here 
  eg. [-1,-2,-3,-4]

Step1 ->-1 is the max value among all subarray.
Step2-> sum ->-10
     -> mini subarray ->-10

    So  sum-mini_subarray 
      => -10-(-10)
      =>0

    so here max(step1,step2)
            max(-1,0)
            =>0 as the answer which is wrong.

4)So here when sum==mini_subarray we return maxx as our answer always.



Code-: Time->O(N)  Space ->O(1)
int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxx=nums[0];
        int curr_sum1=nums[0];
        int sum=nums[0];
        int mini=nums[0];
        int curr_sum2=nums[0];

        
        for(int i=1;i<n;i++)
        {
            //max subarray sum
            curr_sum1=max(curr_sum1+nums[i],nums[i]);
            maxx=max(maxx,curr_sum1);

            //sum
            sum+=nums[i];

            //min subarray sum
             curr_sum2=min(curr_sum2+nums[i],nums[i]);
             mini=min(mini,curr_sum2);
        }
        if(sum==mini)
        return maxx;
        else
        return max(maxx,sum-mini);
}