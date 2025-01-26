https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/0

Question -:
[1,2,3,6] -:

Solution -: 
[1,2,6]
[1,3,6]

But question said we want largest array as my answer. 

Steps-:
1)same approach. 
2)just we are sorting previous when any possible answer we have to print.
  But -: 
  Here we want largest array. 
3)so we sorted in a decreasing order. 
 sort(nums.begin(),nums.end(),greater<int>());

 [6,3,2,1]

  [6,3,1] 

4)we add the largest element first so that my answer array will be largest.


Code-:
vector<int> largestDivisibleSubset(vector<int>&nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>temp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        
       
        int maxx=1;
        int index=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if( (nums[j]%nums[i]==0))
                {
                    if(temp[i]<1+temp[j])
                    {
                      temp[i]=1+temp[j];
                      hash[i]=j;
                    }
                }
            }
            if(maxx<temp[i])
            {
                maxx=temp[i];
                index=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[index]);
        while(hash[index]!=index)
        {
            index=hash[index];
            ans.push_back(nums[index]);
        }
        return ans;
    }