#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <sstream>

using namespace std;
int ans = 0, n = 0;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
    TreeNode(int _x, TreeNode* _left, TreeNode* _right) {
        val = _x;
        left = _left;
        right = _right;
    }
};

int maxDepth_recur(TreeNode* root) {
    if(root == NULL)
        return 0;
    int left_tree_depth = maxDepth_recur(root->left);
    int right_tree_depth = maxDepth_recur(root->right);
    return max(left_tree_depth, right_tree_depth)+1;
}

void preorderTraversal(vector<int>& res, TreeNode* root) {
    if(root != NULL) {
        res.push_back(root->val);
        preorderTraversal(res, root->left);
        preorderTraversal(res, root->right);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorderTraversal(res, root);
    return res;
}

void inorderTraversal(vector<int>& res, TreeNode* root) {
    if(root != NULL) {
        inorderTraversal(res, root->left);
        res.push_back(root->val);
        inorderTraversal(res, root->right);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderTraversal(res, root);
    return res;
}

void postorderTraversal(vector<int>& res, TreeNode* root) {
    if(root != NULL) {
        postorderTraversal(res, root->left);
        postorderTraversal(res, root->right);
        res.push_back(root->val);

    }
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorderTraversal(res, root);
    return res;
}

bool isSymmetric(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->val != root2->val)
        return false;
    return isSymmetric(root1->left, root2->right) &&
           isSymmetric(root1->right, root2->left);
}

bool isSymmetric(TreeNode* root) {
     return isSymmetric(root, root);
}

bool hasPathSum(TreeNode* root, int sum) {
    
}

bool isValidBST(TreeNode* root) {

}

// The following is the solver of diameterOfBinaryTree
int ans;
int depth(TreeNode* rt) {
    if(rt == NULL) return 0;
    int L = depth(rt->left);
    int R = depth(rt->right);
    ans = max(ans, L+R+1);
    return max(L, R)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    ans = 1;
    depth(root);
    return ans-1;
}

//
TreeNode* mirrorTree(TreeNode* root) {
    if(root == NULL) return NULL;

    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if(root->left)
        mirrorTree(root->left);
    if(root->right)
        mirrorTree(root->right);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, inorder, 0, 0, inorder.size() - 1);
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int root, int start, int end){// 中序的start和end
    if(start > end) return NULL;
    TreeNode *tree = new TreeNode(preorder[root]);
    int i = start;
    while(i < end && preorder[root] != inorder[i]) 
        i++;
    tree->left = build(preorder, inorder, root + 1, start, i - 1);
    tree->right = build(preorder, inorder, root + 1 + i - start, i + 1, end);
    return tree;
}

int gitDeep(TreeNode* root) {
    if(root == NULL) return 0;
    int l = gitDeep(root->left);
    int r = gitDeep(root->right);
    if(l < 0 || r < 0 || l - r >= 2 || r-l >= 2)
        return -1;
    return max(l, r)+1;
}

bool isBalanced(TreeNode* root) {
   if(root == NULL) return true;
   return gitDeep(root) > 0;
}

void dfs(TreeNode* root, int k) {
    if(root == NULL) return;
    if(root->right) dfs(root->right, k);
    n++;
    if(n == k) ans = root->val;
    if(root->left) dfs(root->left, k);
}

int kthLargest_recur(TreeNode* root, int k) {
    dfs(root, k);
    return ans;
}

int kthLargest_loop(TreeNode* root, int k) {
    stack<TreeNode*> sk;
    int n = 0;
    while(!sk.empty() || root) {
        while(root) {
            sk.push(root);
            root = root-> right;
        }
        root = sk.top();
        sk.pop();
        n++;
        if(n == k) return root->val;
        root = root -> left;
    }
    return 0;
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(A == NULL || B == NULL) return false;
    return hasSubstructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool hasSubstructure(TreeNode* A, TreeNode* B) {
    if(B == NULL) return true;
    if(A == NULL) return false;
    if(A->val != B->val) return false;
    return hasSubstructure(A->left, B->left) && hasSubstructure(A->right, B->right) ;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        ans.push_back(node->val);
        if(node->left) que.push(node->left);
        if(node->right) que.push(node->right);
    }
    return ans;
}

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    int nextlevel = 0, curlevel = 1;
    queue<TreeNode*> que;
    que.push(root);
    vector<int> tmp;
    while(!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        tmp.push_back(node->val);
        curlevel--;
        if(node->left) {
            que.push(node->left);
            nextlevel++;
        }
        if(node->right) {
            que.push(node->right);
            nextlevel++;
        }
        if(curlevel == 0) {
            ans.push_back(tmp);
            curlevel = nextlevel;
            nextlevel = 0;
            tmp.clear();
        }
    }
    return ans;

}

vector<vector<int>> levelOrder3(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> que;
    que.push(root);
    bool is_left = false;
    while(!que.empty()) {
        int levellen = que.size();
        vector<int> tmp;
        for(int i = 0; i < levellen; i++) {
            TreeNode* node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        is_left = !is_left;
        if(!is_left) ans.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
        else ans.push_back(tmp);
    }
    return ans;
}

bool verifyPostorder(vector<int>& postorder) {
    if(postorder.size() < 1) return true;
    stack<int> sk;
    int pre = INT_MAX;
    for(int i = postorder.size()-1; i >= 0; i--) {
        if(postorder[i] > pre)
            return false;
        while(sk.size() && postorder[i] < sk.top()) {
            pre = sk.top();
            sk.pop();
        }
        sk.push(postorder[i]);
    }
    return true;
}

void backtrack(TreeNode* root, int sum, vector<vector<int>> ans, vector<int> tmp) {
    tmp.push_back(root->val);
    if(sum == root->val && root->left == NULL && root->right == NULL)
        ans.push_back(tmp);
    if(root->left) backtrack(root->left, sum-root->val, ans, tmp);
    if(root->right) backtrack(root->right, sum-root->val, ans, tmp);
    tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(root == NULL) return {};
    vector<vector<int>> ans;
    vector<int> tmp;
    backtrack(root, sum, ans, tmp);
    return ans;
}

void helper(TreeNode* root, TreeNode*& head, TreeNode*& pre) {
    if(root == NULL) return;
    helper(root->left, head, pre);
    if(!head) {
        head = root;
        pre = root;
    } else {
        pre->right = root;
        root->left = pre;
        pre = root;
    }
    helper(root->right, head, pre);
}

TreeNode* treeToDoublyList(TreeNode* root) {
    if(root== NULL) return NULL;
    TreeNode* head = nullptr, *pre = nullptr;
    helper(root, head, pre);
    head->left = pre;
    pre->right = head;
    return head;
}

/*
void kthSmallestCore(TreeNode* root, int k, int& n, int& ans) {
    if(root==NULL) return;
    if(root->left) kthSmallestCore(root->left, k, n, ans);
    n++;
    if(n == k) ans = root->val;
    if(root->right) kthSmallestCore(root->right, k, n, ans);
}

int kthSmallest(TreeNode* root, int k) {
    if(root==NULL) return 0;
    int ans = 0;
    int n = 0;
    kthSmallestCore(root, k, n, ans);
    return ans;
}
*/

// 二叉树
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || p == root || q == root) return root;
    TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightnode = lowestCommonAncestor(root->right, p, q);
    if(leftnode == NULL) return rightnode;
    if(rightnode == NULL) return leftnode;
    return root;
}


TreeNode* deserialize(string data) {
    istringstream input(data);
    string val;
    vector<TreeNode*> vec;
    while(input >> val) {
        if(val == "null") vec.push_back(NULL);
        else vec.push_back(new TreeNode(stoi(val)));
    }
    int j = 1;
    for(int i = 0; j < vec.size(); ++i) {
        if(vec[i] == NULL) continue;
        if(j < vec.size()) vec[i]->left = vec[j++];
        if(j < vec.size()) vec[i]->right = vec[j++];
    }
    return vec[0];
}

// the helper function for deleteNode
TreeNode* min(TreeNode* node) {
    if(node->left == NULL)
        return node;
    return min(node->left);
}

TreeNode* deleteMin(TreeNode* node) {
    if(node->left == NULL)
        return node->right;
    node->left = deleteMin(node->left);
    return node;
}

/** leetcode-450 删除二叉搜索树节点
 *  @param: the root node of the tree and the key of the delete node
 *  @return: the deleted tree root Node
 */
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(key < root->val) {
        root->left = deleteNode(root->left, key);
        return root;
    } else if(key > root->val) {
        root->right = deleteNode(root->right, key);
        return root;
    } else {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL) 
            return root->left;
        else {
            TreeNode* successor = min(root->right);
            successor->right = deleteMin(root->right);
            successor->left = root->left;
            return successor;
        }
    }
}

int main() {

    return 0;
}