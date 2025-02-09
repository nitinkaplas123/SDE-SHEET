Solution 1-:
Steps-:
1)Given strings are sorted as per Aliens.
2)Firstly make a graph of character (convert it into index ) 
  a -> 0
  b -> 1
  c -> 2
  d -> 3
        0    1    2    3   4
eg. -> [baa,abcd,abca,cab,cad]
here -:
   compare 
1)baa vs abcd    -> b<a
2)abcd vs abca   -> d<a
3)abca vs cab    -> a<c
4)cab vs cad     -> b<d 

graph -:
b->a 
d->a 
a->c 
b->d 

3)now do simply the topological sort.


Code-:
string findOrder(vector<string> dict, int k) {
        int n=dict.size();
        vector<int>adj[k];
        for(int k=0;k<n-1;k++)
        {
            string s1=dict[k];
            string s2=dict[k+1];
            
            int i=0;
            int j=0;
            int n1=s1.length();
            int n2=s2.length();
            while(i<n1 and j<n2)
            {
                if(s1[i]!=s2[j])
                {
                   adj[s1[i]-'a'].push_back(s2[j]-'a');
                   break;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }
        
        vector<int>inDegree(k);
        for(int i=0;i<k;i++)
        {
            for(auto x:adj[i])
            {
                inDegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<k;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        string ans="";
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            ans+=(val+'a');
            
            for(auto x:adj[val])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                q.push(x);
            }
        }
        if(ans.length()!=k) return {};
        else
        return ans;
}