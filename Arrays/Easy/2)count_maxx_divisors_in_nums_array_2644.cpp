Solution 1:

Edges case 
nums={1} divisors={5,7,5}

divisor
5 : 0
2 : 0 
5 : 0 

which means all the divisors has 0 count in nums array. 
So when we have same count then we have to choose the smallest element as our ans.

O/P -: 5 

Intution :
1)Thats why we take maxx_count=-1 as in intialisation.

Time Complexity: O(n*m)
Space Complexity: O(1)
Code:
int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n1=nums.size();
        int n2=divisors.size();
        int ans=0;
        int maxxCount=-1;

        for(int i=0;i<n2;i++)
        {
            int count=0;
            int div=divisors[i];
            for(int j=0;j<n1;j++)
            {
                if(nums[j]%div==0)
                count++;
            }
            if(count>maxxCount)
            {
                ans=div;
                maxxCount=count;
            }
            else if(count==maxxCount and ans>div)
            ans=div;
        }
        return ans;
}


Solution 2:

Intution :
1)smallest divisors has more elements in nums which increase its divisorScore.
2)So if divisors ka length is greater than 100 then just find the smallest 7 values.
3)To find the first 7 then sort the divisors array.
Why 7?


Code:
int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n1=nums.size();
        int n2=divisors.size();
        int ans=0;
        int maxxCount=-1;

        sort(divisors.begin(),divisors.end());
        if(n2>100)
        n2=7;

        for(int i=0;i<n2;i++)
        {
            int count=0;
            int div=divisors[i];
            for(int j=0;j<n1;j++)
            {
                if(nums[j]%div==0)
                count++;
            }
            if(count>maxxCount)
            {
                ans=div;
                maxxCount=count;
            }
            else if(count==maxxCount and ans>div)
            ans=div;
        }
        return ans;
    }