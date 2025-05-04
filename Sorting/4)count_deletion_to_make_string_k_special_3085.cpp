Solution 1:

Steps:
1) if the i value is 4 then maximum j value will be 4+k to satisfied the condition.
   only then 4-(4+k)<=k

   4-4-k<=k
   k<=k

2) Case1 :
   if(arr[i]>arr[j])
   delete all the characters of j 
   count+=arr[j].

   Case2:
   if(arr[i]<arr[j])
   diff=arr[j]-arr[i];
   count+=diff-k.


Dry run:
a->4
b->2
c->1

[4,2,1]
minDeletion=INT_MAX
1) i=0 

   j=1 
   count+=2

   j=2
   count+=1

   count=3

minDeletion=3.

   [4,2,1]
2) i=1 

   j=0 
   diff=2
   count=2

   j=2 
   diff=1
   count=2+1

   minDeletion=3.


3) [4,2,1]
   i=2

   j=0
   diff=3
   count=3

   j=1
   diff=1
   count=3+1

   minDeletion=3.


o/p -: 3


Means we pointing to every value using i and traverse all the rest using j.


Time -: O(N) + O(26) 
n -: for traversing the word length
freq: freq array where maxx we have 26 characters.

Space : O(26).

Code:
int minimumDeletions(string word, int k) 
{
        int n = word.length();
        unordered_map<char, int> m;

        for (int i = 0; i < n; i++) {
            m[word[i]]++;
        }

        vector<int> freq;
        for (auto x : m) {
            freq.push_back(x.second);
        }

        int minDel = INT_MAX;
        for (int i = 0; i < freq.size(); i++) 
        {
            int count=0;
            for(int j=0;j<freq.size();j++)
            {
                if(i==j) continue;

                if(freq[i]>freq[j])
                count+=freq[j];
                else
                {
                    int diff=freq[j]-freq[i];
                    if(diff>k)
                    count+=diff-k;
                }
            }
            minDel=min(minDel,count);
        }
        return minDel;
}