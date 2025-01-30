Steps-:
1)There is 2*n elements. 
2)Divide it into two arrays left,right.
eg. [3,9,7,3]

left->[3,9] 
right->[7,3]

3)Now as we make two subsets of 2 len each here those abs diff is minimum as possible.
        2 here       2 here. 
  means []            []

4) for that we use find all subsets problem. 

[3,9] -> [0],[3][9],[3+9]

        0    1    2
sum1-> [0],[3,9],[12]     -> sum of 0 elements, sum of 1 element, sum of 2 elements. 
we store no. of elements sum like this.


[7,3]   -> [0],[7][3],[10]

         0    1    2
sum2 -> [0],[7,3],[10]


5)Now its time to make different different combination of two elements each and make a min diff. 

                                           0    1    2
        0    1    2               sum2 -> [0],[7,3],[10]
sum1-> [0],[3,9],[12]          

we sort the sum2 vector for implement lower_bound on it.

6) Now we traverse over sum1 array. 
   now we have to select 2 elements for subset1  -> rest sum-(s1 subset) is for subset s2.
   i=0 -> means no element we take from sum1.

   it means n-i we have to take from sum2.
   we pass solve(sum1[i],sum2[n-i]);
   to pass both vector to find min possible combination.

7) Solve function -: 
                         
   sum1 -> [0]          sum2 -> [10]
   now we have to choose s1 subset and s2 subset \
   but here we choose s1 subset and s2 will be total_sum-s1.

   i=0 -> sum1[i] -> 0 
   
   now total=22 

if we divide as half half -> 11 and 11 
what is the abs diff bw them ?
0. 


So s1 subset i want 11.             s2 subset i want 11.
from sum1 i choose -: 
sum1[i]-> 0 

now from sum2 i choose -> (target-sum1[i]) -> 11

8) here we are using lower_bound on 11 -> which gives 1 
   
   s1 subset -> sum1[i] + sum2[index-1] or sum2[index] depend upon index value.
             -> 0 + 10 
             -> 10.
   
 Note-:  imagination for min sum diff. 

          s1 subset -> [11]             s2 subset -> [11]

          Here actual -:

          s1 subset -> [10]              s2 subset -> [12]   -> s2->(sum-s1)
          abs diff bw two subset is 2 .


  formula -> sum- 2*(10) 
             22 -20 
             =2

  formula -> sum - 2*(sum1[i]+sum2[index])


9) Three cases -:
   1. when index=0 ->                     sum2[index].
   2. when index==n  =>                   sum2[index-1].
   3. when index is in bw of 0 and n -> then as we are calculating abs diff we have to check both points one step ahead and one step back.
                                     ->    sum2[index] and sum2[index-1]. 
                                    



Time Complexity -:  O(2^n log(2^n))



Code-:
class Solution {
public:
    void helper(vector<int>&nums,int index,int n,int sum,int count,vector<vector<int>>&sum1)
    {
         if(index==n)
         {
             sum1[count].push_back(sum);
             return ;
         }
         helper(nums,index+1,n,sum,count,sum1);
         sum+=nums[index];
         helper(nums,index+1,n,sum,count+1,sum1);
    }

    int solve(vector<int>&nums1,vector<int>&nums2,int total)   
    {
        int n=nums1.size();
       
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int target=total/2-nums1[i];
            
            int index=lower_bound(nums2.begin(),nums2.end(),target)-nums2.begin();
            if(index==0)
            {
               mini=min(mini,abs(total-2*(nums1[i]+nums2[index])));
            }
            else if(index==nums2.size())
            {
               mini=min(mini,abs(total-2*(nums1[i]+nums2[index-1])));
            }
            else
            {
               mini=min(mini,abs(total-2*(nums1[i]+nums2[index-1])));
               mini=min(mini,abs(total-2*(nums1[i]+nums2[index])));
            }
        }
        return mini;
    }
    
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        n=n/2;
        vector<int>left,right;
        int total=0;
        for(int i=0;i<n;i++){                  // O(N)
            left.push_back(nums[i]);
            right.push_back(nums[n+i]);
            total+=nums[i];
            total+=nums[n+i];
        }

        vector<vector<int>>sum1(n+1);
        vector<vector<int>>sum2(n+1);
        
        helper(left,0,n,0,0,sum1);       // O(2^N)
        helper(right,0,n,0,0,sum2);

        for(int i=0;i<sum2.size();i++)    // O(2^n log(2^n))
        {
           sort(sum2[i].begin(),sum2[i].end());
        }
        
        int minDiff=INT_MAX;
        for(int i=0;i<sum1.size();i++)       // O(2^n log(2^n)) as in sum1 we have 2^n elements so here we are running on 2^n elements.
                                             // log(2^n) because in solve function we are using lower_bound function.
        {
            int val=solve(sum1[i],sum2[n-i],total);
            minDiff=min(minDiff,val);
        }
        return minDiff;
    }
};