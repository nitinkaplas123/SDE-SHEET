Solution 1-:
Steps-:
1)Add all the first column values in pq and its row,col  -> {val,{row,col}}.

Time->O(K^2(logK))
Space->O(K)
Code-:
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<K;i++)
        {
            pq.push({arr[i][0],{i,0}});
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            ans.push_back(val);
            
            if(col+1<K)
            {
                pq.push({arr[row][col+1],{row,col+1}});
            }
        }
        return ans;
}