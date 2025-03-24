Solution 1:
Steps:
1)Make a visited array of size days+1 -> mark false.
2)Now go to every range and make as true -> true means we have meeting that day.
3)Now at the end traverse the visited array and count how many times we have visited false which tells -> we donot have meeting on that day. 
4)Return count.

Time ->O(N*d)) where d is the diff bw meeting end-start.  Space->O(days)
int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<bool>visited(days+1,false);
        for(int i=0;i<n;i++)
        {
            int start=meetings[i][0];
            int end=meetings[i][1];
            for(int j=start;j<=end;j++)
            {
                visited[j]=true;
            }
        }

        int count=0;
        for(int i=1;i<=days;i++)
        {
            if(visited[i]==false)
            count++;
        }
        return count;
}


Solution 2:

Steps:
1)Its may be overlapping.  -> So convert it into non-overlapping intervals.
2)Now we find the days used [1,3] -> which means 3 days is used for meeting. 
  totaldays-=(3-1+1)


[1,3],[2,4]  days=5

1. Merge intervals 
   [1,4]

2. days=days-(4-1+1)
   days=1.

Time->O(Nlog(N))
Space->O(N)  for storing vector of vector v.

int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());

        vector<vector<int>>v;
        v.push_back(meetings[0]);

        for(int i=1;i<n;i++)
        {
            if(meetings[i][0]<=v.back()[1] and v.back()[1]<=meetings[i][1])
            v.back()[1]=meetings[i][1];
            else if(meetings[i][0]>v.back()[1])
            v.push_back(meetings[i]);
            else
            continue;
        }

        for(int i=0;i<v.size();i++)
        {
            int diff=(v[i][1]-v[i][0])+1;
            days-=(diff);
        }
        return days;
}



Solution 3: (Space optimised)
Steps:
1) Using pointers => 
   prevStart=meeting[0][0]
   prevEnd=meeting[0][1]

i=1 
currStart=meetings[i][0]
currEnd=meetings[i][1]

now check if these 2 are overlapping then update prevEnd with max value.

else
calculate the diff 


Time -: O(Nlog(N)) Space->O(1)


Code-:
int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());

        int prevStart=meetings[0][0];
        int prevEnd=meetings[0][1];

        for(int i=1;i<n;i++)
        {
            int currStart=meetings[i][0];
            int currEnd=meetings[i][1];

            //overlapping
            if(prevEnd>=currStart)
            prevEnd=max(prevEnd,currEnd);
            else
            {
               int daysUsed=prevEnd-prevStart+1;
               days-=daysUsed;
               prevStart=currStart;
               prevEnd=currEnd;
            }
        }
        days-=(prevEnd-prevStart+1);
        return days;
}