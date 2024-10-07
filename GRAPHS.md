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

### DFS

```cpp
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    // traverse all its neighbours
    for(auto it : adj[node]) {
        // if the neighbour is not visited
        if(!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}
```

### BFS

```cpp
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    // push the initial starting node
    q.push(0);
    vector<int> bfs;
    // iterate till the queue is empty
    while(!q.empty()) {
        // get the topmost element in the queue
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // traverse for all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour has previously not been visited,
            // store in Q and mark as visited
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
```

## BFS WITH ADJCENCY MATRIX

```CPP
    void bfs(int node, vector<vector<int>> &isConnected, vector<int> &visited, int n){
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; i++){
            if (!visited[i] and isConnected[x][i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected){
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            bfs(i, isConnected, visited, n);
            count++;
        }
    }
    return count;
}
```

## DIJKSTRA S ALGO

```cpp
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){

    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(V, INT_MAX);

    // Source initialised with dist=0.
    distTo[S] = 0;
    pq.push({0, S});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node]){
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + w, v});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}
```

- Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.

- Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.

1.  Given an undirected acyclic graph with all of the vertices having at most 3 neighbors. Please find a vertex in the tree so that after setting the vertex as root it forms a valid binary tree

Observation

- Given graph is a tree -> such that each node has maximum 3 edges.

- We are given a tree; where each node <= 3 edges.
- We have to decide which node should be selected as the root so that the tree becomes a binary tree.
- Each node of a binary tree has 2 children.
- The input tree will have this property - each node will have at max 2 children except the root node. (-> root node can have 3 children which distorts the validity of being a binary tree.)

- SOL: Select a node which has 2 edges or 1 edge(best option) - then it can always be converted to a binary tree.

- -> Proof :- The only problem is that the root of the input tree might have 3 children or else the problem is already solved. The root is assumed for input tree is the answer if it is already attached to two nodes only

- -> In case; the root has 3 child; then selecting the leaf of the tree always works.

```
     1
   / | \
   2 3  4
  / \    \
 5   6    7
```

===

```
     3
     |
     1
   /  \
   2    4
  / \    \
 5   6    7
```
