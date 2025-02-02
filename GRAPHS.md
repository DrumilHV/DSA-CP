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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap ,

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
            int vertex = it[0];
            int weight = it[1];
            if (dis + weight < distTo[v])
            {
                distTo[vertex] = dis + weight;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + weight, vertex});
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

- USING SET

```cpp
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    // Create a set ds for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    // set stores the nodes in ascending order of the distances
    set<pair<int,int>> st;

    // Initialising dist list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> dist(V, 1e9);

    st.insert({0, S});

    // Source initialised with dist=0
    dist[S] = 0;

    // Now, erase the minimum distance node first from the set
    // and traverse for all its adjacent nodes.
    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        // Check for all adjacent nodes of the erased
        // element whether the prev dist is larger than current or not.
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgW = it[1];

            if(dis + edgW < dist[adjNode]) {
                // erase if it was visited previously at
                // a greater cost.
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                // If current distance is smaller,
                // push it into the queue
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
                }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return dist;
}
```

1.  Given an undirected acyclic graph with all of the vertices having at most 3 neighbors. Please find a vertex in the tree so that after setting the vertex as root it forms a valid binary tree

- Observation

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

2. You are maintaining a project that has n methods numbered from 0 to n - 1. You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

- There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
- A group of methods can only be removed if no method outside the group invokes any methods within it.
- Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

```
Example 1:
Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
Output: [0,1,2,3]
Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.
Example 2:
Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
Output: [3,4]
Explanation:
Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.
Example 3:
Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
Output: []
Explanation:
All methods are suspicious. We can remove them.
```

```cpp
vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
    // Create an adjacency list to represent the graph of method invocations
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        // For each edge (u, v), method u invokes method v
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);  // Add v to the list of methods invoked by u
    }

    // Create a visited array to track suspicious methods (methods invoked directly/indirectly by k)
    vector<int> vis(n, 0);

    // Lambda function to perform depth-first search (DFS)
    // This will mark all methods directly or indirectly invoked by method k as suspicious
    auto dfs = [&](auto &&dfs, int u) {
        if (vis[u]) return;  // If the method u is already visited, stop
        vis[u] = 1;          // Mark method u as visited (suspicious)
        for (int v : adj[u]) {
            dfs(dfs, v);      // Recursively visit all methods invoked by u
        }
    };

    // Perform DFS starting from method k to mark all suspicious methods
    dfs(dfs, k);

    // Flag to determine whether we need to keep all methods
    bool takeAll = false;

    // Check if any method outside the suspicious group invokes a suspicious method
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        // If method u is not suspicious but it invokes a suspicious method v,
        // we cannot safely remove the suspicious group
        if (!vis[u] && vis[v]) {
            takeAll = true;  // Set the flag to indicate that we must keep all methods
            break;
        }
    }

    // Create a vector to store the remaining methods
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // If we must keep all methods (takeAll is true) or the method is not suspicious,
        // add it to the result
        if (takeAll || !vis[i]) {
            ans.push_back(i);
        }
    }
    // Return the final list of remaining methods
    return ans;
}
```
