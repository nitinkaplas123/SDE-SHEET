// Space -> 
// Trie Storage -> O(N*L) for making the trie where N is the no. of string and L will be the length of string.

// Time->
// O(N* (Llog(L)+ 26*L) for sorted string + insertion -> O(N*Llog(L))
// dfs -> N*L 

// Time Complexity -> O(N*Llog(L))

// C++
// Code-:

// class TrieNode
// {
//    public:
//    TrieNode* children[26];
//    vector<string>words;

//    TrieNode()
//    {
//       for(int i=0;i<26;i++)
//       {
//         children[i]=NULL;
//       }
//    }
// };

class Solution {
public:
    void insert(TrieNode* root,string str,string sortedStr)
    {
        int n=str.length();
        TrieNode* curr=root;
        for(char ch:sortedStr)
        {
            int index=ch-'a';
            if(curr->children[index]==NULL)
            curr->children[index]=new TrieNode();
            curr=curr->children[index];
        }
        curr->words.push_back(str);
    }
    void dfs(TrieNode* node,vector<vector<string>>&ans)
    {
          if(node->words.empty()==false)
          ans.push_back(node->words);

          for(int i=0;i<26;i++)
          {
             if(node->children[i]!=NULL)
             dfs(node->children[i],ans);
          }

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        TrieNode* root=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            string sortedStr=strs[i];
            sort(sortedStr.begin(),sortedStr.end());
            insert(root,strs[i],sortedStr);
        }
        vector<vector<string>>ans;
        dfs(root,ans);
        return ans;
    }
};




Java Code-:
class TrieNode {
    TrieNode[] children;
    List<String> words;

    TrieNode() {
        children = new TrieNode[26]; // For each letter a-z
        words = new ArrayList<>(); // Stores the list of words at this node
    }
}

class Solution {
    public void insert(TrieNode root, String original, String sortedStr) {
        TrieNode current = root;

        // Traverse the sorted string and create Trie nodes
        for (char ch : sortedStr.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }

        // Add the original string to the words list at the leaf node
        current.words.add(original);
    }

    public void dfs(TrieNode node, List<List<String>> result) {
        // If the node contains words, add them to the result
        if (node.words.isEmpty()==false) {
            result.add(node.words);
        }

        // Recursively traverse all children
        for (int i = 0; i < 26; i++) {
            if (node.children[i] != null) {
                dfs(node.children[i], result);
            }
        }
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        TrieNode root = new TrieNode();

        // Insert each string into the Trie
        for (String str : strs) 
        {
            char[] chars = str.toCharArray();
            Arrays.sort(chars); // Sort the string
            String sortedStr = new String(chars);
            insert(root, str, sortedStr);
        }

        // Perform DFS on the Trie to collect grouped anagrams
        List<List<String>> result = new ArrayList<>();
        dfs(root, result);

        return result;
    }
}




class Solution {
    public void merge(int[] arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        
        int[] left = new int[n1];
        int[] right = new int[n2];
        
        // Copy data to left and right arrays
        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        
        for (int i = 0; i < n2; i++) {
            right[i] = arr[mid + 1 + i];
        }
        
        int i = 0, j = 0;
        int k = low;
        
        // Merge the temp arrays back into arr[]
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        
        // Copy remaining elements of left[]
        while (i < n1) {
            arr[k++] = left[i++];
        }
        
        // Copy remaining elements of right[]
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
    
    public void mergeSort(int[] arr, int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);  // Sorting the left half
            mergeSort(arr, mid + 1, r);  // Sorting the right half
            merge(arr, l, mid, r);  // Merging the sorted halves
        }
    }
}