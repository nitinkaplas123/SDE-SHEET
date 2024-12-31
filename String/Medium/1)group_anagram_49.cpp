Solution 1-:
Steps-:
1)using hashmap.

Code-:
vector<vector<string>> groupAnagrams(vector<string>&arr) {
        vector<vector<string>>ans;
        int n=arr.size();
        
        unordered_map<string,vector<string>>m;
        for(int i=0;i<n;i++)
        {
            string str=arr[i];
            sort(arr[i].begin(),arr[i].end());
            m[arr[i]].push_back(str);
        }
        
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
}