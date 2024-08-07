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
```

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

    // BFS traversal
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
