https://www.geeksforgeeks.org/problems/max-length-chain/1


Solution 1-:
Steps-:
1)sort the array according to first value.  
  or 
  according to second also working fine.
2)now do the lis on it.

Why we have to sort 

arr[]={{6,8},{3,4}}

Case1 -:
without sort -> ans -> 1

Case2 -:
with sort -: 
arr[]={{3,4},{6,8}}

ans=2 (length is 2).



Code-: Time->O(N^2)
static bool comp(val &val1,val & val2)
{
        return val1.first<val2.first;
}

int maxChainLen(struct val p[],int n)
{
       sort(p,p+n,comp);
       
       vector<int>temp(n+1,1);
       int ans=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(p[i].first>p[j].second)
               temp[i]=max(temp[i],1+temp[j]);
           }
           ans=max(ans,temp[i]);
       }
       return ans;
}




Solution 2-:
Idea-:
1)Same as activity selection problem.
2)We have pair of array where pair is (starting time) and (ending time).
3)We need to count max meeting we can arrange.
4)here prev => end time of meeting 
       p[i].first => starting time of meeting.

       

5)Sort the array according to end time of meeting.
  why end ?
  because start_time<end_time.
  so i need the smallest end time to starting the meeting or 
  starting the counting part.


 start=> 7 6 2 7 3
 end =>  10 6 10 9 5

 start time o/p -> 1 
 end time o/p   -> 3
Code-:
static bool comp(val &val1,val & val2)
{
        return val1.second<val2.second;
}

int maxChainLen(struct val p[],int n)
{
       sort(p,p+n,comp);
       
       int count=1;
       int prev=p[0].second;
       for(int i=1;i<n;i++)
       {
           if(prev<p[i].first)
           {
               count++;
               prev=p[i].second;
           }
       }
       return count;
}

