https://www.geeksforgeeks.org/problems/word-ladder/1


Time->O(M*N *26)   -> where m is the no. of strings and n is the len of string and in each time we are replacing with str='a' to str='z'.

Code-:
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
         int n=wordList.size();
         unordered_set<string>set;
         for(int i=0;i<n;i++){
             set.insert(wordList[i]);
         }
         
         queue<pair<string,int>>q;
         q.push({startWord,1});
         
         while(!q.empty())
         {
             string str=q.front().first;
             int len=q.front().second;
             q.pop();
             
             if(str==targetWord)
             return len;
            
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