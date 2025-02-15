Solution 1-:
Steps-:
1)Using 2 for loop.


Time->O(N^2)
Code-:
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int val=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                val*=nums[j];
            }
            ans.push_back(val);
        }
        return ans;
}


Solution 2-:
Steps-: (Using divide method.)
1)Firstly i count all the zeros in array and have a multiply of all in mul variable.

Case1-: (If the curr element is non-zero)
    1. if count==0 means there is no zeros in array.
       val=mul/nums[i].
    2. if(count>0) means if curr element is not zero then out of all rest of the elements there is 0 we have.
       val=0.

Case2-: (If curr element is zero).
    1. if(count==1) means curr is zero and total count is also zero which means mul is my ans.
       val=mul.
    2. if(count>1) curr element is zero and count>1 means if i exclude curr element there is for sure zero bcz count>1 that zero makes me 0.
       val=0.


Time->O(N)
Space->O(1)
Code-:
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int mul=1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) count++;
            else mul*=nums[i];
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                if(count==0) ans.push_back(mul/nums[i]);
                else ans.push_back(0);
            }
            else
            {
                if(count==1)  ans.push_back(mul);
                else ans.push_back(0);
            }
        }
        return ans;
}



Solution 3-:
we have to find multiplication of ith index except ith value.

Steps-:
1)So at point i calculate the product of all the element in left side of i.
2) calaculate the product of all element in right side of i.
3) val=left[i]*right[i]


## left[0]=1 and right[n-1]=1 bcz nothing is there in its left and in its right.
## rest of case.
left[i]=prev element of left[i-1] store all the mul of its left. 
        now i want to add its arr[i-1] as well in the product.

left[i]=left[i-1] * arr[i-1].

Similarliy of right side.
right[i]=arr[i+1]*right[i+1].

Time->O(N)
Space->O(N)
Code-:
 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        vector<int>ans(n,1);
        
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }

        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++)
        {
            ans[i]=left[i]*right[i];
        }
        return ans;
}


Solution 4-:
Steps-:
1)In prev sol we first make a prefix array (left) and then make a suffix array (right)
  then we multiply of prefix[i]*suffix[i] and store it in a ans vector.
But What i am saying at the end we have to multiply prefix and suffix na and have to store in ans vector.

So-:
1)we can directly store the prefix in ans vector.
2)then we can do the suffix part in and multiply and ans[i]*suffix.


Code-:
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        
        
        int suffix=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
                  //preix * suffix.
           ans[i]=ans[i]*suffix;
           suffix*=nums[i];
        }
        return ans;
}


