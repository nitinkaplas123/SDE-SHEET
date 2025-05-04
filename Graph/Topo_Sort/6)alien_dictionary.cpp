Solution 1-:
Steps-:
1)Given strings are sorted as per Aliens.
2)Firstly make a graph of character (convert it into index ) 
  a -> 0
  b -> 1
  c -> 2
  d -> 3
        0    1    2    3   4
eg. -> [baa,abcd,abca,cab,cad]
here -:
   compare 
1)baa vs abcd    -> b<a
2)abcd vs abca   -> d<a
3)abca vs cab    -> a<c
4)cab vs cad     -> b<d 

graph -:
b->a 
d->a 
a->c 
b->d 

3)now do simply the topological sort.


Code-:
string alienOrder(vector<string>& words) 
{
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        unordered_set<char> chars;

        // Step 1: Initialize all unique characters
        for (const string& word : words) {
            for (char ch : word) {
                chars.insert(ch);
                inDegree[ch] = 0;  // Make sure every char is in inDegree
            }
        }

        // Step 2: Build graph
        for (int i =0;i<words.size()-1;i++) 
        {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());

            int j;
            for (j=0;j<len;j++) 
            {
                if (w1[j] != w2[j]) 
                {
                    adj[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    break;
                }
            }

            // If word2 is a prefix of word1 and word1 is longer => invalid
            if (j==len && w1.size() > w2.size())
            return "";
        }

        // Step 3: Topological sort (Kahn's algorithm)
        queue<char> q;
        for (char ch : chars) {
            if (inDegree[ch] == 0) q.push(ch);
        }

        string result;
        while (!q.empty()) {
            char ch = q.front(); q.pop();
            result += ch;
            for (char neighbor : adj[ch]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        // If result doesn't include all characters => cycle
        return result.size() == chars.size() ? result : "";
    }



or
here we change the build graph

Code: 
string alienOrder(vector<string>& words) {
        int n=words.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        unordered_set<char> chars;

        // Step 1: Initialize all unique characters
        for (const string& word : words) {
            for (char ch : word) {
                chars.insert(ch);
                inDegree[ch] = 0;  // Make sure every char is in inDegree
            }
        }

        // Step 2: Build graph
        for(int k=0;k<n-1;k++)
        {
            string word1=words[k];
            string word2=words[k+1];

            int i=0;
            int j=0;
            int n1=word1.length();
            int n2=word2.length();
            while(i<n1 and j<n2)
            {
                if(word1[i]==word2[j])
                {
                    i++;
                    j++;
                }
                else 
                {
                    adj[word1[j]].push_back(word2[j]);
                    inDegree[word2[j]]++;
                    break;
                }
            }
            // If word2 is a prefix of word1 and word1 is longer => invalid
            if (j == n2 && n1 > n2)
            return "";
        }

        // Step 3: Topological sort (Kahn's algorithm)
        queue<char> q;
        for (char ch : chars) {
            if (inDegree[ch] == 0) q.push(ch);
        }

        string result;
        while (!q.empty()) {
            char ch = q.front(); q.pop();
            result += ch;
            for (char neighbor : adj[ch]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        // If result doesn't include all characters => cycle
        return result.size() == chars.size() ? result : "";
}