Steps-:
1)if my topo sort array element == numCourses
  means there is no cycle.

Intution -:
1)in toposort 
  u->v
  means u phele aaega v se.

Here [a,b]
b phele aaega a se.

so just change the order of u and v.


Code-:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>ans;
       int n=prerequisites.size();

       vector<int>adj[numCourses];
       for(int i=0;i<n;i++)
       {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
       }

       int inDegree[numCourses];
       for(int i=0;i<numCourses;i++)
       {
        inDegree[i]=0;
       }

       for(int i=0;i<n;i++)
       {
          int u=prerequisites[i][0];
          int v=prerequisites[i][1];
          inDegree[u]++;
       }

       queue<int>q;
       for(int i=0;i<numCourses;i++)
       {
           if(inDegree[i]==0)
           q.push(i);
       }

      

       while(q.empty()==false)
       {
          int val=q.front();
          q.pop();

          ans.push_back(val);

          for(auto x:adj[val])
          {
             inDegree[x]--;
             if(inDegree[x]==0)
             q.push(x);
          }
       }
       if(ans.size()!=numCourses)
       return {};
       else
       return ans;
}



Solution 2-:
Steps-:
1)Same first convert into inDegree part.
2)then count==numCourses -> return {ans}; 
  else return {};



Code-:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            int first=prerequisites[i][0];
            int second=prerequisites[i][1];
            prerequisites[i][0]=second;
            prerequisites[i][1]=first;
        }

        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++)
        {
            int first=prerequisites[i][0];
            int second=prerequisites[i][1];
            adj[first].push_back(second);
        }

        vector<int>inDegree(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            for(auto x:adj[i])
            {
                inDegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }

        vector<int>ans;
        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();
            ans.push_back(val);

            for(auto x:adj[val])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                q.push(x);
            }
        }
        if(ans.size()==numCourses)
        return ans;
        else
        return {};
}