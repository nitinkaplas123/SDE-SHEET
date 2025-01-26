Code-:
class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second==b.second)
        return a.first>b.first;
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }

        vector<pair<int,int>>v;
        for(auto x:m)
        { 
           v.push_back({x.first,x.second});  
        }

        sort(v.begin(),v.end(),comp);

        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
           int val=v[i].first;
           int freq=v[i].second;
           while(freq--)
           {
              ans.push_back(val);
           }
        }
        return ans;
    }
};