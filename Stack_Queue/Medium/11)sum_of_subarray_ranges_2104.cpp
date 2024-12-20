Solution 1-:
Steps-:
1)make all the subarrays and store it in a 2d vector.
2)now run all the subarrays and find the mini and maxi out of it.
3)now make a sum and add all the difference of mini and maxi in it.

Code-: Time->O(N^2) Space->O(N^2)
long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            vector<int>v1;
            for(int j=i;j<n;j++)
            {
               v1.push_back(nums[j]);
               v.push_back(v1);
            }
        }

        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
             if(v[i].size()==1)
             continue;
             
             int mini=INT_MAX;
             int maxi=INT_MIN;
             for(int j=0;j<v[i].size();j++)
             {
                mini=min(mini,v[i][j]);
                maxi=max(maxi,v[i][j]);
             }
             sum+=(maxi-mini);
        }
        return sum;
}



Solution 2-:
Steps-:
1)Run a 2 for loop and make mini and maxi for all subarrays.
2)do the sum of max-mini;
3)return sum.


EG. -> [1,2,3]
i=0
[1]      -> 0 
[1,2]    -> 1
[1,2,3]  -> 2

i=1
[2]      -> 0
[2,3]    -> 1

i=2
[3]      -> 0

Total ->    4

Code-: Time->O(N^2) Space->O(1)
long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
       
        long long sum=0;
        for(int i=0;i<n;i++)
        {    
             int mini=INT_MAX;
             int maxi=INT_MIN;
             for(int j=i;j<n;j++)
             {
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);
                sum+=(maxi-mini);
             }
        }
        return sum;
}



Solution 3-:

Intution-:
1)Find the sum of mini value in all subarrays.
2)Find the sum of maxi value in all subarrays.

EG. -> [1,2,3]
i=0                    maxi
[1]      -> 1          1
[1,2]    -> 1          2
[1,2,3]  -> 1          3

i=1
[2]      -> 2          2
[2,3]    -> 2          3

i=2
[3]      -> 3          3

mini_sum -> 10   maxi  14

return maxi_sum-mini_sum;


Steps-:
1)Use the same idea in subarray of mini sum question.

Here we are finding the sum of mini sum in all subarrays.
2)There we find the sum of all elements in all subarrays using -> prev_smaller and next_smaller -> using stack.

Here we are finding the sum of maxi elements in all subarrays.
3)There we find the sum of all elements in all subarrays using -> prev_greater and next_greater -> using stack.



Code-: Time->O(N) Space->O(N)
long long int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev;
        
        stack<int>st1;
        st1.push(0);
        prev.push_back(1);
        for(int i=1;i<n;i++)
        {
            while(st1.empty()==false and arr[st1.top()]>arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            prev.push_back(i+1);
            else
            prev.push_back(i-st1.top());
            st1.push(i);
        }
        
        vector<int>next;
        next.push_back(1);
        stack<int>st2;
        st2.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            while(st2.empty()==false and arr[st2.top()]>=arr[i])
            {
                st2.pop();
            }
            if(st2.empty())
            next.push_back(n-i);
            else
            next.push_back(st2.top()-i);
            st2.push(i);
        }
        reverse(next.begin(),next.end());
        
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
           long long int subarrays=(prev[i]*next[i]);
           long long val=(long long)arr[i] * subarrays;
           sum=(sum+val);
        }
        return sum;
}

long long int sumSubarrayMaxi(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev_greater;
        
        stack<int>st1;
        st1.push(0);
        prev_greater.push_back(1);
        for(int i=1;i<n;i++)
        {
            while(st1.empty()==false and arr[st1.top()]<arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            prev_greater.push_back(i+1);
            else
            prev_greater.push_back(i-st1.top());
            st1.push(i);
        }
        
        vector<int>next_greater;
        next_greater.push_back(1);
        stack<int>st2;
        st2.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            while(st2.empty()==false and arr[st2.top()]<=arr[i])
            {
                st2.pop();
            }
            if(st2.empty())
            next_greater.push_back(n-i);
            else
            next_greater.push_back(st2.top()-i);
            st2.push(i);
        }
        reverse(next_greater.begin(),next_greater.end());
        
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
           long long int subarrays=(prev_greater[i]*next_greater[i]);
           long long val=(long long)arr[i] *subarrays;
           sum=(sum+val);
        }
        return sum;
}

long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long int mini_sum=sumSubarrayMins(nums);
        long long int maxi_sum=sumSubarrayMaxi(nums);
        return maxi_sum-mini_sum;
}