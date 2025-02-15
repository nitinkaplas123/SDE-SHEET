makeFriend(x,y)
{
    union(x,y)
}

Steps-:
1)Here makeFriends means we have to connect the x and y node so that they become friends so each other.
2)This connection can be done with the help of union function in disjoint sets.

boolean areFriend(x,y)
{
    return find(x)==find(y);
}

Steps-:
1)This can be done with the help of find function where we call 
  1. find(x) -> which gives the representative/leader of set where x is present.
  2. find(y) -> which gives the representative of set where y is present.

  if(both x and y are in same set which means its representative are also same)
  
  Case1-: if both x and y are belong to same set.   (friends of each other).
          then they have same leader.

          in this case -> return true.
  
  Case2-: if both are in different subset then its representative are also different.
          if this case -> return false.


Time Complexity -> O(N) for normal bfs, dfs approach.

By using union by rank -;
Time Complexity -: O(logn)

By using union by rank and path compression -:
Time Complexity -: O(1) amortized.






