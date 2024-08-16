### full binary tree

- all levels filled
- has either 0 or 2 children

### complete binary tree

- all levels filled except possibly the last level
- all nodes in the last level are as far left as possible

### degnerate trees

- its a skewd bt with all nodes at only one side
- like a linked list

### balanced binary tree

- max height is log(n)

### Traversal

- inorder -> left root right

```cpp
void preorder(root){
    if(!root){ return; }
    preorder(root->left);
    cout << root->data;
    preorder(root->right);
}
```

- postorder -> left right root

```cpp
void preorder(root){
    if(!root){ return; }
    preorder(root->left);
    preorder(root->right);
    cout << root->data;
}
```

- preorder -> root left right

```cpp
void preorder(root){
    if(!root){ return; }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
```

```
            1
          /    \
        2       3
      /   \    /   \
    4     5   6     7
```

- inorder: 4 2 5 1 6 3 7
- postorder: 4 5 2 6 7 3 1
- preorder: 1 2 4 5 3 6 7

## LEVEL ORDER TRAVERSAL

```cpp
void LevelOrderTraversal(root){
    queue<TreeNode*> root;
    vector<vector<int>> ans;
    if(!root){
        return;
    }
    q.push(root);
    while(!q.empty){
        int size = q.size();
        vector<int> level;
        for(int i =0;i<size;i++){
            TreeNode * temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}
```

## preorder traversal

```cpp
vector<int> preorderTraversal(TreeNode * node){
    vector<int> preorder;
    if(!node) return preorder;
    stack<TreeNode *> st;
    st.push(node);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right){
            st.push_back(root->right);
        }
        if(root->left){
        st.push_back(root->left);
        }
    }
    return preorder;
}
```

## Inorder

```cpp
vector<int> inorderTraversal(TreeNode * root){
    vector<int> inorder;
    TreeNode * node  = root;
    stack<TreeNode *> st;
    while(!st.empty()){
        if(node){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}
```

## Postorder

```cpp
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> res;

    while(!st.empty() || root != NULL){
        if(root != NULL){
            st.push(root);
            root= root->left;
        }
        else{
            TreeNode* temp = st.top()->right;

            if(temp == NULL){
                temp = st.top();
                st.pop();
                res.push_back(temp->val);

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                }
            }
            else{
                root = temp;
            }
        }
    }
    return res;
}
```

# LEVEL ORDER TRAVERSAL

````cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i =0;i<size;i++){
            TreeNode * temp  = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
    }
```

1. RIGHT / LEFT VIEW OF TREE.

- use preorder traversal of tree.
- when level == size of array push - back the number
- when left is asked do root left right
- when right is asked do root right left

```cpp
void helper(TreeNode * root, vector<int> & rv, int level){
    if(!root) return ;
    if(rv.size()==level){
        rv.push_back(root->val);
    }
    helper(root->right, rv, level+1);
    helper(root->left, rv, level+1);
    }
````

2. bottom view of tree

```cpp
vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if(node->left != NULL){
            q.push({node->left, line - 1});
        }
        if(node->right != NULL){

            q.push({node->right, line + 1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
    }
```

3. top view

```cpp
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    // BFS traversal
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->data;
        }
        if(node->left != NULL){
            q.push({node->left, line - 1});
        }
        if(node->right != NULL){
            q.push({node->right, line + 1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }

    return ans;
}
```

4. Boundary elemets

- do left
- do leaves (you can do it many times if req)
- do right

```cpp
bool isleaf(Node* node) {
        return (node->left == nullptr && node->right == nullptr);
}

void addleftboundary(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur) {
        if (!isleaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addrightboundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isleaf(cur)) tmp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; i--) {
        res.push_back(tmp[i]);
    }
}

void addleaves(Node* root, vector<int>& res) {
    if (isleaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) addleaves(root->left, res);
    if (root->right) addleaves(root->right, res);
}

vector<int> boundary(Node* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    if (!isleaf(root)) res.push_back(root->data);
    addleftboundary(root, res);
    addleaves(root, res);
    addrightboundary(root, res);
    return res;
}
```

5. DIAMETER OF A BINARY TREE

```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int height(TreeNode *root, int &diameter){
    if(root==NULL){return 0;}
    int lh = height(root->left,diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh+rh);
    return 1+max(lh,rh);
}
```

6. RETURN IF TREES ARE SYMETRICALL (MIRROR IMAGE)

```cpp
bool isMirror(TreeNode * t1, TreeNode * t2){
    if(t1==NULL && t2==NULL) return true;
    if(t1 == NULL || t2 == NULL) return false;

    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
```

7. MAXIMUM WIDTH OF TREE: MAX DIFF B/W ANY TOW NODES OF THE SAME LEVEL

```CPP
int widthOfBinaryTree(TreeNode* root) {
    long long int ans = 0;
    queue<pair<TreeNode *,int>> q;
    int tempCount = 1;
    q.push({root,tempCount++});
    int maxW = INT_MIN;
    while(!q.empty()){
        int n = q.size();
        int start = 0;
        int end = 0;
        for(int i =0;i<n;i++){
            TreeNode * currNode  = q.front().first;
            int currIdx = q.front().second;
            q.pop();
            if(i==0){
                start = currIdx;
            }
            if(i==n-1){
                end  = currIdx;
            }
            if(currNode->left){
                q.push({currNode->left, (ll) 2*currIdx + 1});
            }
            if(currNode->right){
                q.push({currNode->right, (ll) 2*currIdx + 2});
            }
        }
        maxW = max(maxW, end-start+1);
    }
    return maxW;
    }
```

8. CHECK IF BINRAY TREE IS BALANCED

```CPP
bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}
int dfsHeight(TreeNode *root){
    if(root == NULL) return 0;
    int lh = dfsHeight(root->left);
    if(lh==-1) return -1;
    int rh = dfsHeight(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}
```

9. LEAST COMMON ANCISTOR

- do dfs
- if any p || q found return that node
- if root == null return null
- there will have 2 conditions only either null or node , so if null => path is over
- if getting a node => found the correct thing
- if both left traversal and right traversal are not null => this is LCA
- if left == null, right is LCA
- else left is LCA

```cpp
TreeNode * solve(TreeNode* root , TreeNode* p, TreeNode* q){
    if(root == NULL) return NULL;
    if(root  == p || root  == q ) return root;

    TreeNode* left  = solve(root->left,p,q);
    TreeNode* right = solve(root->right,p,q);

    if(left != NULL && right!=NULL) return root;

    if(left == NULL) return right;
    return left;
    }
```

10. MAX PATH SUM

```cpp
int mSum(TreeNode * root, int &sum){
    if(root==NULL) return 0;
    int ls = max(0,mSum(root->left, sum));
    int rs = max(0,mSum(root->right, sum));
    sum = max(sum, ls+rs+root->val);
    return max(ls,rs)+root->val;
}
```

11. [Time for Tree to burn](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/) : every node and burns one second, the next second its adjcent nodes burn. return the time for burning the entire tree.

- make tree to graph.
- so you can travers to parent nodes also when you have to .
- do bfs to keep track to time, no of levels starting from start node to end node is time .
- or do dfs to find the time / no of levels.

```cpp
    vector <vector<int>> graph;
    vector <bool> vis;
    int res = 0;
    void go(TreeNode* root){
        if(!root) return;

        int val = root->val;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        if(leftNode){
            int l = leftNode->val;
            graph[val].push_back(l);
            graph[l].push_back(val);
        }
        if(rightNode){
            int r = rightNode->val;
            graph[val].push_back(r);
            graph[r].push_back(val);
        }
        go(leftNode);
        go(rightNode);
    }
    void dfs(int node, int w){
        vis[node] = true;
        res = max(res, w);
        for(auto child: graph[node]){
            if(!vis[child])
            dfs(child, w + 1);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        graph.resize(1e5 + 7);
        vis.resize(1e5 + 7);
        go(root);
        dfs(start, 0);
        return res;
    }
```

12. [Children sum property](https://www.geeksforgeeks.org/problems/children-sum-parent/1) : check if all the parent node are sum of their childern nodes if so return 1 eles 0.

```cpp
int isSumProperty(Node *root){
    if(!root) return 1;
    if(!root->left && !root->right) return 1;
    int left = 0, right =0;
    if(root->left) left = root->left->data;
    if(root->right) right = root->right->data;
    return root->data == left+right && isSumProperty(root->left) && isSumProperty(root->right);
}
```

13. print nodes of at a distance of k from given node

- convert to graph
- use dfs/bfs to find the levels of distace of other nodes to given nodes

```cpp
vector<vector<int>> graph;
vector<bool> v;
vector<int> ans;
void makeGraph(TreeNode * root){
    if(!root) return ;
    TreeNode * left = root->left;
    TreeNode * right = root->right;
    int val = root->val;
    if(left){
        int l = left->val;
        graph[val].push_back(l);
        graph[l].push_back(val);
    }
    if(right){
        int r = right->val;
        graph[val].push_back(r);
        graph[r].push_back(val);
    }
    makeGraph(left);
    makeGraph(right);
}
void dfs(int tgt, int level, int k){
    v[tgt] = true;
    if(level==k){
        ans.push_back(tgt);
    }
    for(auto i: graph[tgt]){
        if(!v[i]) dfs(i, level+1, k);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    graph.resize(507);
    v.resize(507, false);
    makeGraph(root);
    dfs(target->val, 0, k);
    return ans;
}
```
