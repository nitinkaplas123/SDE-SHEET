https://www.geeksforgeeks.org/problems/word-ladder-ii/1

Code-:
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       vector<vector<string>>ans;

        unordered_set<string>set(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        vector<string>usedWord;
        q.push({beginWord});
        int level=0;

        while(!q.empty())
        {
            vector<string>list=q.front();
            string word=list.back();
            q.pop();

            if(list.size()>level)
            {
                level++;
                for(int i=0;i<usedWord.size();i++)
                {
                    if(set.find(usedWord[i])!=set.end())
                    set.erase(usedWord[i]);
                }
                usedWord.clear();
            }
            

            if(word==endWord)
            ans.push_back(list);
            
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(set.find(word)!=set.end())
                    {
                        usedWord.push_back(word);
                        list.push_back(word);
                        q.push({list});
                        list.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
}