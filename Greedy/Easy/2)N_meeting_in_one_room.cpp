https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Code-: Time->O(Nlog(N))
static bool comp(pair<int,int>&a,pair<int,int>&b)
{
        return (a.second<b.second);
}

int maxMeetings(int n, int start[], int end[]) {
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       {
           v.push_back({start[i],end[i]});
       }
       
       sort(v.begin(),v.end(),comp);
       
       int count=1;
       int prev=v[0].second;
       for(int i=1;i<n;i++)
       {
           if(prev<v[i].first)
           {
               count++;
               prev=v[i].second;
           }
       }
       return count;
}