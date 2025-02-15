https://www.geeksforgeeks.org/problems/word-ladder-ii/1


Solution 1-:
Steps-:
1) Here we use the same idea of word ladder1.
2) But here question i want all the paths from start to end.
3) So we cannot erase immedaitely.

startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}


          der 

     dfr        des

dfs                  dfs 


Level 1.
4) 1. So here when we are using der 
      and we get dfr so donot delete immediately.
   2. then using der 
      we have des. 

Level 2 -> dfr -> dfs 
           des -> dfs. 

So here if we see using dfr -> we got dfs so if we delete dfs from set now.
  then how we can make another path which is from 
  des-> dfs (at that time our set said we donot have dfs.)


Note -: Delete level by level from set so that we can make all possible path.



Time->O()
Code-:
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       vector<vector<string>>ans;
       int n=wordList.size();
       vector<string>used;
       unordered_set<string>s{wordList.begin(),wordList.end()};
       queue<vector<string>>q;
       q.push({beginWord});
       
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