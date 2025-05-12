Solution 1:

d->5
a->1
b->2
c->3

[5,1,2,3]

1)Run the loop for i->0
  we assumed the 5 is the minFreq while making k speacil word. 
  [5,1,2,3]

  5>1 
  removed all occuarnce of a->1
  count=1

  5>2
  removed all occuarnce of b->2.
  count=1+2

  5>3
  removed all occuarnce of c->3.
  count=1+2+3

  minDeletion =6 when we assume d->5 is the minOcuurance.

2)1)Run the loop for i->1  
   [5,1,2,3]  arr[i]=1

   1)arr[j]-arr[i]>k
     5-1>2
     remove the 5-1-2 occurabce from 5 which is 2.
     deletion=2.

   2)2-1<=k.
   no deletion needed.

   3)3-1<=k
   no deletion needed.

   minDeletion=min(6,2) => 2.

3)Run the loop for i->2
4)Run the loop for i->3.



Intution :
1)we assumed the minFreq


     min      max
mod(freq[i]-freq[j])<=k

if(freq[i]==5)
then to satisfy the condition the max value of freq[j] is:
freq[j]=5+k

 min  max
|5-(5+k)|<=k

not more than 5+k.

1)So here we assume always as we have mod 
  freq[i] is smaller than freq[j]
mod(freq[i]-freq[j])<=k

Case1:
if(freq[i]>freq[j]) deletion all the occurance of freq[j].

Case2: 
if(freq[j]-freq[i]>k)
then deletion the occurance of freq[j] by 
freq[j]-freq[i]-k.





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
int minimumDeletions(string word, int k) {
        int n=word.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[word[i]-'a']++;
        }
        
        int minDel=INT_MAX;
        for(int i=0;i<26;i++)
        {
            int deletion=0;
           for(int j=0;j<26;j++)
           {
               if(i==j) continue;

               if(freq[i]>freq[j])
               deletion+=freq[j];
               else 
               {
                  if(freq[j]-freq[i]>k)
                  deletion+=(freq[j]-freq[i]-k);
               }
           }
           minDel=min(minDel,deletion);
        }
        return minDel;
    }