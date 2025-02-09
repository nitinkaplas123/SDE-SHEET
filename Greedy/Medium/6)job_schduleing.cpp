https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Solution 1-:
Steps-:
1)Reverse Sort the array acc to profit 
  means -> max profit -> to lower profit.
2)Make an array of size n.
3)Now store the profit at that index which is empty.
  
  i=deadline-1;i>=0;i--

4)At last traverse the array where the value is !=-1 means u add the profit over there. 
5) Increase the count and add the profit. 


Key Steps-:
1)we want max profit -> reverse sort the array acc to profit.
2)delay the day means try to complete the task from deadline-1 to 0.

Time->O(N^2)
Space->O(1)
Code-:
static bool comp(pair<int,int>&a,pair<int,int>&b)
{
        return a.second>b.second;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        
        int n=profit.size();
        
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({deadline[i],profit[i]});
        }
        sort(v.begin(),v.end(),comp);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int val=v[i].first;
            for(int j=val-1;j>=0;j--)
            {
                if(ans[j]==-1){
                ans[j]=v[i].second;
                break;
                }
            }
        }
        
        int count=0;
        int val=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=-1)
            {
                count++;
                val+=ans[i];
            }
        }
        return {count,val};
}



Solution 2-:
Steps-:
1)sort the array acc to deadline  0 to n. 
2)Now here deadline -> curr from 1 to n. 
3)if u are able to complete the task before deadline then add the profit into pq.
  else if(profit>pq.top)
  then erase the top element 
  add the curr->profit.

Time->O(Nlog(N))
Space->O(N)
Code-:

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n=profit.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({deadline[i],profit[i]});
        }
        sort(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        int curr=1;
        
        for(int i=0;i<n;i++)
        {
            if(v[i].first>=curr)
            {
                pq.push(v[i].second);
                curr++;
            }
            else if(v[i].second>pq.top())
            {
                pq.pop();
                pq.push(v[i].second);
            }
        }
        
        int count=pq.size();
        int pro=0;
        while(!pq.empty())
        {
            pro+=pq.top();
            pq.pop();
        }
        return {count,pro};
}