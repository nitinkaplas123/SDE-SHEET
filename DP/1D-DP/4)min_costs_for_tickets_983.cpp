 0 1 2 3 4 5
[1,4,6,7,8,20]
Solution 1-:
Steps-:
1)here we have 3 options for buying ticket 
  1-day pass 
  7-day pass
  30-day pass 
2)so we go for all possible cases 

index=0;
Case1-:
option1-> costs[0]+helper(index+1)

Case2-:
here we have 7 day pass so where we are now+7 days we can utilised. 
i=index  ;  days[i]<1+7  ;i++ 
for(i=index;i<n and days[i]<days[index]+7;i++);
so here i=4 where we stop and (i<n) so that we take care of out of bound as well. 

option2-> costs[1]+helper(i);

Case3-:

Similarily for case3 just do +30 instead of +7 

for(i=index;i<n and days[i]<days[index]+30;i++);

Code-:
int helper(vector<int>&days,vector<int>&costs,int index,int n)
{
        if(index>=n) return 0;
        int option1=costs[0]+helper(days,costs,index+1,n);
        int i;
        for(i=index;i<n and days[i]<days[index]+7;i++);
        int option2=costs[1]+helper(days,costs,i,n);
        for(i=index;i<n and days[i]<days[index]+30;i++);
        int option3=costs[2]+helper(days,costs,i,n);
        return min(option1,min(option2,option3));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        return helper(days,costs,0,n);
}




Solution 2-:
Steps-:
1)using memo 

Code-:
int helper(int memo[365],vector<int>&days,vector<int>&costs,int index,int n)
{
        if(index>=n) return 0;
        if(memo[index]!=-1) return memo[index];
        int option1=costs[0]+helper(memo,days,costs,index+1,n);
        int i;
        for(i=index;i<n and days[i]<days[index]+7;i++);
        int option2=costs[1]+helper(memo,days,costs,i,n);
        for(i=index;i<n and days[i]<days[index]+30;i++);
        int option3=costs[2]+helper(memo,days,costs,i,n);
        return memo[index]=min(option1,min(option2,option3));
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int memo[365];
        memset(memo,-1,sizeof(memo));
        return helper(memo,days,costs,0,n);
}