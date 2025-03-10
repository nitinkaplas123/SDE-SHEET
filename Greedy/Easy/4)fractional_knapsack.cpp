Solution 1-:
Steps: 
1)Sort acc to value/weight ratio.
  value/weight ratio will be largest at the start.

2)If W>=wt[]
  add 

  else 
  take the ratio of it.
  and then break the loop.



Code-:
static bool comp(pair<int,int>&a, pair<int,int>&b)
{
        double r1=(double)a.first/a.second;
        double r2=(double)b.first/b.second;
        return (r1>r2);
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int W) {
        int n=val.size();
        vector<pair<int,int>>items;
        for(int i=0;i<n;i++)
        {
            items.push_back({val[i],wt[i]});
        }
        
        sort(items.begin(),items.end(),comp);
        
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(W>=items[i].second)
            {
                ans+=(double)items[i].first;
                W-=items[i].second;
            }
            else
            {
                double val=(double)items[i].first/items[i].second;
                ans+=val*W;
                break;
            }
        }
        return ans;
}