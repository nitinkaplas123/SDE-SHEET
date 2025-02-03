


Time->O(M*N *26)   -> where m is the no. of strings and n is the len of string and in each time we are replacing with str='a' to str='z'.

Code-:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();

        unordered_set<string>set(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty())
        {
            string str=q.front().first;
            int len=q.front().second;
            q.pop();

            if(str==endWord) return len;

            for(int i=0;i<str.length();i++)
            {
                char original=str[i];
                for(char ch='a';ch<='z';ch++)
                {
                    str[i]=ch;
                    if(set.find(str)!=set.end())
                    {
                        q.push({str,len+1});
                        set.erase(str);
                    }
                }
                str[i]=original;
            }
        }
        return 0;
}