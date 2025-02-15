Note -: Disjoint set is like tree strcuture.
        for eg. if we have 3 values who are in a single subset 
        then its form a tree among themselve.
        and where root is the representative for all the nodes.

Note -: All child nodes of a tree has a common representative which is called root.
        Root does not have parent so here root ka represenative is itself.


Note -: We make an array of parent where we store the representative in that.


For eg. [1,2,3,4,5]

Intial we have these values. 
so its connected to itself.

Node 1 is connected to itself. its representative is itself.
Node 2 is connected to itself. its representative is itself.
Node 3 is connected to itself. its representative is itself.
Node 4 is connected to itself. its representative is itself.
Node 5 is connected to itself. its representative is itself.


parent -> [1,2,3,4,5]

Now -> union(1,2)

which looks like ->    1->2 where 1 is the root node. and 2 is the child 
                       node 1 ka representative is 1   (root)
                       node 2 ka representative is 1.  (root)

For that updation we update in parent array.

before -: 
parent -> [1,2,3,4,5]

After-: 
union(1,2)

parent -> [1,1,3,4,5]



