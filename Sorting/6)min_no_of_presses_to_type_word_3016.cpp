Solution 1:


Steps:
1)As we have max of 26 characters, so we firstly find the freq of each in a word.
2)Then we sort the vector acc to max freq at the front.
3)Now traverse the vector, as in a phone, we have 8 diff space buttons, see in a question 
  diagram.So maxx we have 26 distinct characters. 
4) So we placed first 8 at the-:
 1. first_place in 8 diff spaces.  -> 1*freq
 2. next8 at second_place.         -> 2*freq
 3. next8 at third_place.          -> 3*freq
 4. next_2 at 4th place.           -> 4*freq

Code:
int minimumPushes(string word) {
        int n=word.length();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
        {
            m[word[i]]++;
        }

        vector<pair<int,char>>v;
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());

        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            // if(i<=7)
            // ans+=(v[i].first);
            // else if(i>=8 and i<=15)
            // ans+=(v[i].first*2);
            // else if(i>=16 and i<=23)
            // ans+=(v[i].first*3);
            // else
            // ans+=(v[i].first*4);
            ans+=(i/8+1)*v[i].first;
        }
        return ans;
}


Solution 2:

Time Complexity -: O(N)
Space Complexity -: O(26)
Code:
int minimumPushes(string word) {
        vector<int>letterFreq(26,0);
        for(int i=0;i<word.length();i++)
        {
            letterFreq[word[i]-'a']++;
        }

        sort(letterFreq.rbegin(), letterFreq.rend());

        int totalPresses=0;
        for(int i=0;i<26;i++)
        {
            if(letterFreq[i]==0) break;
            totalPresses+=(i/8+1)*letterFreq[i];
        }
        return totalPresses;
}