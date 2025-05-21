Solution 1:
Steps:
1)Using hashMap




Solution 2:

Steps:
1)as its greater by n/3 so if we have n elements then max there will be 2 elements 

Note -: either 2, either 1 or nothing, but not more than 2 elements.
n -> n/3 +n/3 + something else than n/3 


Time ->O(N)
Space ->O(1)
Code:
vector<int> majorityElement(vector<int>& nums) 
{
        int n=nums.size();
        int num1=INT_MIN;
        int num2=INT_MIN;
        int c1=0;
        int c2=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
            c1++;
            else if(nums[i]==num2)
            c2++;
            else if(c1==0)
            {
                num1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        int count1=0;
        int count2=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1) count1++;
            if(nums[i]==num2) count2++;
        }
        if(count1>n/3) ans.push_back(num1);
        if(count2>n/3) ans.push_back(num2);
        return ans;
}