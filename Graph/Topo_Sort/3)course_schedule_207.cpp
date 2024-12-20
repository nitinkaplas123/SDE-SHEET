Intution -:
1) [1,0] -> [a,b]
    here question said if u want to buy course a first u have to buy b.

    [0,1] is the answer.

whenever someone said [u,v] -> u before v or (v before u).
which algo came to my mind is topological sort.


Note -:
1)topo sort is working for DAG which is Directed Acyclic Graph.
2)means if there is cycle means its not follow the topo sort properties.


Task -:
1)return true if we can buy all the courses else return false.


Steps-:
1)here we just have to check if (topo arr ==n) means there is no cycle 
2)means we can buy all the courses.


Code-:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
       return false;
       else
       return true;
}



Solution 2-:
Steps-:
1)In topo sort -> u->v  here u first then v 
2) Here        -> u->v  here v first then v.

3)lets make same topo inDegree question fot that we just have to swap the u->v values. 
here we swap it.
for(int i=0;i<n;i++)
{
   int first=prerequisites[i][0];
   int second=prerequisites[i][1];
   prerequisites[i][0]=second;
   prerequisites[i][1]=first;
}


Code-:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            int first=prerequisites[i][0];
            int second=prerequisites[i][1];
            prerequisites[i][0]=second;
            prerequisites[i][1]=first;
        }

        vector<int>adj[numCourses];
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

        int count=0;
        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();
            count++;

            for(auto x:adj[val])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                q.push(x);
            }
        }
        return (count==numCourses);
}


