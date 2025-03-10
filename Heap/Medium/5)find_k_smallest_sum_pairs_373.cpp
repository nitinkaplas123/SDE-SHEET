Solution 1-:
Steps-:
1)Make min heap and make all possible pairs and add it into min heap.
2)run while k times and extract k pairs from the top.

Time->O(N1*N2*log(N1*N2))
Space->O(N1*N2)
Code-:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n1=nums1.size();
        int n2=nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum=nums1[i]+nums2[j];
                pq.push({sum,{nums1[i],nums2[j]}});
            }
        }

        while(k--)
        {
            int val1=pq.top().second.first;
            int val2=pq.top().second.second;
            pq.pop();
            ans.push_back({val1,val2});
        }
        return ans;
}



pq->  {sum,nums1[i],nums2[j]}.
Solution 2-:
Steps-:
1)using max heap.
2)we add only k pairs in max heap.

1) if my size of pq is less than k then add the {sum,nums1[i],nums2[j]}.
2) now if pq.top().first>sum
   means curr_sum is minium as compare to top pairs in max heap.
   let pop the pq.top().
   add the currsum,{num[i],num2[j]}.
3) if(pa.top()<sum)
   break.

   because if sum is big value than pq.top() so now for upcoming pairs which we make from i and j that is bigger beacuse 
   both arrays are sorted.
   so no sense to traverse bcz now in future we got more big values.
   so lets break the loop.


Time->O(N1*N2*log(k))
Space->O(K)
Code-:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n1=nums1.size();
        int n2=nums2.size();
       
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                pq.push({sum,{nums1[i],nums2[j]}});
                else if(pq.top().first>sum)
                {
                   pq.pop();
                   pq.push({sum,{nums1[i],nums2[j]}});
                }
                else
                break;
            }
        }

        while(!pq.empty())
        {
            int val1=pq.top().second.first;
            int val2=pq.top().second.second;
            pq.pop();
            ans.push_back({val1,val2});
        }
        return ans;
}



Solution 3-:
Steps-:
1)using min heap.
2)add the {0,0} values in min heap as {sum,{i,j}} -> where i and j is the index of both the arrays.
3)Now pq will run k times as we need k pairs.
4)
  Now when we add {0,0} -> there is 2 choices -> {0,1} or {1,0}.
  so we add both but take care of out of bound check point over there.

5) and as we are adding 2 indexes at the same time so there is a chance of duplicates. 
   means there is possibility we are adding a pair 2 times using indexes.

   like {0,1}  -> {0,2} or {1,1}

   {1,0}  -> {2,0} or {1,1}

   see {1,1} is coming two times.

Solution is making a set of pair which help us to take care of duplicates indexing.


Time->O(klog(K))
Space ->O(k)
Code-:
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n1=nums1.size();
        int n2=nums2.size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int sum=nums1[0]+nums2[0];
        pq.push({sum,{0,0}});

        set<pair<int,int>>visited;
        visited.insert({0,0});
        
        while(k--)
        {
           int i=pq.top().second.first;
           int j=pq.top().second.second;
           pq.pop();
           
           ans.push_back({nums1[i],nums2[j]});
           
           // check out of bound and pair is already used or not
           if(i+1<n1 and visited.find({i+1,j})==visited.end())
           {
               pq.push({nums1[i+1]+nums2[j],{i+1,j}});
               visited.insert({i+1,j});
           }
           // check out of bound and pair is already used or not
           if(j+1<n2 and visited.find({i,j+1})==visited.end())
           {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
           }
        }
        return ans;
}