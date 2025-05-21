Solution 1-:
Steps-:
1)using hashmap.


Time ->O(Nklog(k)) -> for loop -> N times, inside we sort string -> klog(k)
                   -> nklog(k)
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


Solution 2:


why we are using # in between every count.

Without #
Imagine -> 
1)str => "aabbccccc"

count [2,2,5] => "225"


2) str="aaaaaaaaaaaaaaaaaaaaaabbbbb"

count : [22,5] => "225"


With # 

Imagine -> 
1)str => "aabbccccc"

count [2,2,5] => "#2#2#5"


2) str="aaaaaaaaaaaaaaaaaaaaaabbbbb"

count : [22,5] => "#22#5"

now its not equal which we want.



Time -> O(N*k)  where k is the length of max string in a list.
Code:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();

        unordered_map<string,vector<string>>map;

        // n times 
        for(auto s:strs)
        {
            vector<int>count(26,0);
            //k times
            for(auto ch:s)
            {
                count[ch-'a']++;
            }

            string key;
            // 26 times
            for(int i=0;i<26;i++)
            {
                key+="#"+to_string(count[i]);
            }

            map[key].push_back(s);
        }
       
        for(auto x:map)
        {
            ans.push_back(x.second);
        }
        return ans;
}