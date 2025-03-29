Solution 1-:
Steps-:
1) We make count and temp array where-:
   temp array stores -> lis.
   count array stores -> no. of lis corresponding to lis. 

   means in temp -> temp[4]=3
            count ->count[4]=2;
   which means length of 3 we have 2 count of lis. means there is 2 arrays those lis is 3.

2) 
if(nums[i]>nums[j])
{
    if(temp[i]<temp[j]+1)     // bigger length is making 
    {
        temp[i]=1+temp[j];      
        count[i]=count[j];   // inherit the count[j] in count[i] because j help i to make len big.
    }
    else if(temp[i]==1+temp[j]) // if j said hey i me and urs len is matching then i said okay lets combine to make more no. of lis.
    count[i]+=count[j];
}



3) now using maxx variable we traverse on temp array whereever we see its lis is maxx add the count[index] in ans variable.
   ans+=count[index].
4)return ans;


Time->O(N^2)
Space->O(N)
Code-:
int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>temp(n,1);
        vector<int>count(n,1);
        int maxx=1;
        int index=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(temp[i]<temp[j]+1)
                    {
                        temp[i]=1+temp[j];
                        count[i]=count[j];
                    }
                    else if(temp[i]==1+temp[j])
                    count[i]+=count[j];
                }
            }
            if(maxx<temp[i])
            maxx=temp[i];
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]==maxx)
            ans+=count[i];
        }
        return ans;
}