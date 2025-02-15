https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find


Solution 1-:
Steps-:
1)using parent array,


Find Function -:
1)We have to find the representative of x which is called as root.
2)parent of all is stored in parent array and only root ka parent is root only.
3)So we have a base condition if(par[x]==x) it means this is the root/rep return x. 
  else 
  go to parent of parent until we hit the base case until we not find the root of that subset.


Union -:
1)Question said parent of x is y. (So every time read the question carefully).
2)Find the root of x.
3)Find the root of y.
4)Make par[x_rep]=y_rep.


Find function -:
Time Complexity -: O(N) (find x is leave node) and its a skew tree so we call recursive n times.
Code-:
int find(int par[], int x) {
    if(par[x]==x)
    return x;
    return find(par,par[x]);
}


Time Complexity -: O(2*n) calling 2 times find function.
void unionSet(int par[], int x, int z) {
    int x_rep=find(par,x);
    int y_rep=find(par,z);
    if(x_rep==y_rep) return ; 
    par[x_rep]=y_rep;
}