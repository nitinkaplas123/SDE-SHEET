Solution 1-:
Steps-:
1)here we are storing all the subarray in vector of vector.
2)now in each vector we find the minimum element and add it into the sum.
3)return sum.

Code-: Time->O(N^2) space->O(N^2)
int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            vector<int>v1;
            for(int j=i;j<n;j++)
            {
                v1.push_back(arr[j]);
                v.push_back(v1);
            }
        }

        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<v[i].size();j++)
            {
                mini=min(mini,v[i][j]);
            }
            sum+=mini;
        }
        return sum;
}


Solution 2-:

eg. [3,1,2,4]
All subarrays -:
          Min of all subarrays
1)[3]        ->3
2)[3,1]      ->1
3)[3,1,2]    ->1
4)[3,1,2,4]  ->1
5)[1]        ->1
6)[1,2]      ->1
7)[1,2,4]    ->1
8)[2]        ->2 
9)[2,4]      ->2
10)[4]       ->4
Total ->      17

Code-: Time->O(n^2) Space->O(1)
int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
               mini=min(mini,arr[j]);
               sum+=mini;
            }
        }
        return sum;
}


Solution 3-:
Intution -:
arr[]={1,4,6,7,3,7,8,1}
lets check for element 3 

index  0  1  2  3  4  5  6  7 
                   .
arr[]  1  4  6  7  3  7  8  1
   index of 3 is 4 
1. prev smallest element of 3 is index->0.
   left_count=4-0 -> 4 
2. next smallest element of 3 is index->7
   right_count=7-4-> 3 

no. of subarray we can make with 3 where 3 is the min element in 12 subarrays is -> 4*3-> 12 
used -> 3 -> 12times.
12*3 => 36 

we have to do this with all elements of arrays.

how 4*3 -> 12 subarrays 

Here is the array after trimming : 4,6,7,3,7,8 (len : 6).

What do we want to find?  - Total number of sub-arrays that include 3.
To get that lets split this into multiple subproblems:
if if  sub array starts from 4 and 3 included - we have 3 ways.they are :
4,6,7,3
4,6,7,3,7
4,6,7,3,7,8
simillary the sub array may start at 6 and 3 also included. then again we have 3 ways. they are :
6,7,3
6,7,3,7
6,7,3,7,8
similarly the sub-array can also start with 7, 3. which results in another 6 ways.
Totally 12 (3 + 3 + 3 + 3)  ways.

    
Steps-:
1)find the prev smaller element and store it in prev vector.
2)find the next smaller element and store it in next vector.
3)total times -> ith element we are using -> next[i]-prev[i]
4)sum=sum+ (arr[i]*total_times)
5)return sum.



Dry run -:
arr  ->  [3,1,2,4]
prev ->  [1 2 1 2] 
next ->  [1 3 1 1]

how many times ith element will be minimum in all subarrays times-> next[i]-prev[i];
sum=sum+(arr[i]*times);

return sum;

Code-: Time->O(N)  Space->O(N)
int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
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
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
           long long int subarrays=(prev[i]*next[i])%mod;
           long long val=(arr[i]*subarrays)%mod;
           sum=(sum+val)%mod;
        }
        return sum;
}