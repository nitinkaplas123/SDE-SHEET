Solution 1-:

Steps-:
1)Using map store all freq of it.
2)Checking all using for loop if freq greater than n/2

Code-:  Time->O(N)  Space ->O(N)
int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
       

        for(auto x:m)
        {
            
            if(x.second>n/2)
            return x.first;
        }
        return -1;
    }




Solution 2 -:

Steps-:
1)Majority element is those  count is greater than n/2 and it exist forsure.
2)Which means majority element > all other elements

for eg. 
[2,2,1,1,1,2,2]
here 2 ->4times
here 1->3 times 

so if we add and sub at last we  have count=1 which is of element 2 
So this is the intuition behind it.

Code:
int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int num=nums[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==num)
            count++;
            else 
            {
                count--;
                if(count==0)
                {
                    num=nums[i];
                    count=1;
                }
            }
        }

        count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num) count++;
        }
        return (count>n/2)?num:-1;
}