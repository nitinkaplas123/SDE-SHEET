Solution 1:

Steps:
1)Find the nth row using prev string.
2)return the kth charcter as int.


Time -> O(n*(2^(n-1)))   
n -> using for loop
2^(n-1) -> for building the nth row.

n=3

i=1 -> 0
i=2 -> 01
i=3 -> 0110

for reaching to the ith row (n loop)
inner loop -> 2^(n-1)

Code:
int kthGrammar(int n, int k) {
        string prev="0";
        for(int i=2;i<=n;i++)
        {
            string curr="";
            for(int j=0;j<prev.length();j++)
            {
                if(prev[j]=='0')
                curr+="01";
                else 
                curr+="10";
            }
            prev=curr;
        }
        int ans=prev[k-1]-'0';
        return ans;
}



Solution 2:
Steps:
1)By making binary tree and apply searching in it.


n=4   k=6

n=1                          0
n=2                 0                   1 
n=3           0           1         1        0
n=4      0       1     1    0    1    0    0    1
k=6      1       2     3    4    5    6    7    8 

                                      ans=0
I recomded to make a tree on paper.                                      
2)Here we imagaine a n=4 binary tree 
3)we start from n=4 to n=1 and search as a binary search.

// Iteration 1:

n=4   k=6    rootVal=0(starting from)  
totalNodes=pow(2,n-1)=8 (at last level we are searching the k=6 value out of 8 nodes.)


totalNodes=8
k=6 

divide the totalNodes in two grp left and right and tell me where k is there.
totalNodes/2=4

k is in right side.
so here we ignore all the nodes in left side.

k=6 if we ignore all the nodes in left side means 4 nodes we are ignore at last level.
//right side.
1. now (k=k-totalNodes/2)
2.  nextRootValue -> if(1) -> 10 means right side of 1 is 0
3.                   if(0) -> 01 means right side of 0 is 1.



// left side.
1. k is not changing here as we are ignoring right side.
2. nextRootVal ->if(1)-> 10 left side ->1
               ->if(0)-> 01 left side ->0

   means nextRootVal=rootVal;


// Base case
1) when n==1 means we have 1 node to search so thats my answer.
return rootVal.


// this is the flow of above testCase if u draw a diagram.
0->1->1->0
rootVal->rightSide->leftSide->rightSide.


Do dry run 
Time -> O(N)  
Space ->O(N)  for recursive call stack space.
Code:
int search(int n,int k,int rootVal)
{
        if(n==1)
        return rootVal;

        int totalNodes=pow(2,n-1);
        if(k>totalNodes/2)
        {
            //right side
            int nextRootVal=(rootVal==0)?1:0;
            return search(n-1,k-totalNodes/2,nextRootVal);
        }
        else
        {
            //left side
            int nextRootVal=rootVal;
            return search(n-1,k,nextRootVal);
        }
}
int kthGrammar(int n, int k) {
        return search(n,k,0);
}