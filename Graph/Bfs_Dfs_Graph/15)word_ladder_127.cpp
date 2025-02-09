https://www.geeksforgeeks.org/problems/word-ladder-ii/1

Code-:
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       vector<vector<string>>ans;
       int n=wordList.size();
       vector<string>used;
       unordered_set<string>s{wordList.begin(),wordList.end()};
       queue<vector<string>>q;
       q.push({beginWord});
       
       int level=0;
       if(s.find(beginWord)!=s.end()) s.erase(beginWord);
       
       while(!q.empty())
       {
           
           int size=q.size();
           for(int i=0;i<size;i++)
           {
                vector<string>v=q.front();
                string str=v.back();
                q.pop();
                
                if(str==endWord)
                ans.push_back(v);
                
                for(int i=0;i<str.length();i++)
                {
                  char ch=str[i];
                  for(char ch='a';ch<='z';ch++)
                  {
                   str[i]=ch;
                   if(s.find(str)!=s.end())
                   {
                       v.push_back(str);
                       q.push({v});
                       used.push_back(str);
                       v.pop_back();
                   }
                  }
                  str[i]=ch;
                }
           }
           for(int i=0;i<used.size();i++)
           {
                   if(s.find(used[i])!=s.end())
                   s.erase(used[i]);
           }
           used.clear();
          }
          return ans;
    }