Solution 1-:
Steps-:
1)make an map store its frequency.
2)make a max heap acc to top frequent element.
3)run k while loop add into ans.

Time->O(nlog(n))
Space->O(N)
Code-:
vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }

        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
}


Solution 2-:
Steps-:
1)Using bucket sort.

eg, [1,1,2,2,3] k=2.

Step1-:
        1 2 3
map -> [2,2,1]
max freq-> 2.


Step2-:
1)Now make a bucket of size freq+1.
vector<vector<int>>count(freq+1);
count -> [[],[],[]]

1) i=0 -> [[],[],[1]]
2) i=1 -> [[],[],[1,2]]
3) i=2 -> [[],[3],[1,2]]


Step3-:
1) k=2.
2) most freq elements is at back so traverse from the back.
3) and put the condition of c<k

ans -> [1,2]


Time->O(N)
Space->O(n)
Code-:
vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int freq=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            freq=max(freq,m[nums[i]]);
        }

        vector<vector<int>>count(freq+1);
        for(auto x:m)
        {
            count[x.second].push_back(x.first);
        }
        
        vector<int>ans;
        int c=0;
        for(int i=freq;i>=0 and c<k;i--)
        {
           for(int j=0;j<count[i].size() and c<k;j++)
           {
                ans.push_back(count[i][j]);
                c++;
           }
        }
        return ans;
}