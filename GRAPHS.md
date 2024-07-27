1. count the number of edges connected to a node.
   - check each row to find the number of 1's,

```
   1 - 5 - 0
        |
   3 - 2 - 4


    - adjcency matrix form
        0,1,2,3,4,5,

    0   [0,1,0,0,0,0]
    1   [1,0,1,0,0,1]
    2   [0,1,0,1,1,0]
    3   [0,0,1,0,0,0]
    4   [0,0,1,0,0,0]
    5   [0,1,0,0,0,0]

    SC: Nodes * no of Edges
    TC: O(N) [for one node]

    - adjecency list
    0   [5]
    1   [5]
    2   [3,4,5]
    3   [2]
    4   [2]
    5   [1,2,0]

    TC: O(1) [for one node]
    SC: Nodes  + 2 * No of edges (it is always Nodes + edges because you can have unconneced graphs, and you sitll need to declare the no of nodes.)
    eg: 1 2
        3 4 - 5
    list:

    1   []
    2   []
    3   []
    4   [5]
    5   [4]
```

2. Use list when Node ~ Edges => 1<=Nodes, edges<=10^5,
3. Use Matrix when Nodes < edges (dense graph).
4. which ever smaller use that.
5. Time to calculate all edges matrix O(M\*N), list O(N);
6. BFS:
    - node where you start doing bfs -> source node. 
    
