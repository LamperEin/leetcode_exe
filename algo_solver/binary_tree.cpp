#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>

using namespace std;
int ans = 0, n = 0;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/** leetcode-173 二叉搜索树迭代器
 * 
 */
class BSTIterator {
    stack<TreeNode*> sk;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            sk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = sk.top();
        sk.pop();
        int val = node->val;
        t = t->right;
        while(t) {
            sk.push(t);
            t = t->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sk.empty();
    }
};

int maxDepth_recur(TreeNode* root) {
    if(root == NULL)
        return 0;
    int left_tree_depth = maxDepth_recur(root->left);
    int right_tree_depth = maxDepth_recur(root->right);
    return max(left_tree_depth, right_tree_depth)+1;
}

int maxDepth_loop(TreeNode* root) {

    return 0;
}

void preorderTraversal(vector<int>& res, TreeNode* root) {
    if(root != NULL) {
        res.push_back(root->val);
        preorderTraversal(res, root->left);
        preorderTraversal(res, root->right);
    }
}

void preorderTraversal_loop(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> sk;
    sk.push(root);
    while(!sk.empty()) {
        TreeNode* node = sk.top();
        sk.pop();
        cout << node->val << endl;
        if(node->left)
            sk.push(node->left);
        if(node->right)
            sk.push(node->right);
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

void inorderTraversal_loop(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> sk;
    TreeNode* p = root
    sk.push(p);
    while(!sk.empty()) {
        while(p != NULL) {
           p = p->left;
            sk.push(p);
        }
        if(!sk.empty()) {
            p = sk.top(); sk.pop();
            cout << p->val << endl;
            p = p->right;
        }
    }
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

void postorderTraversal_loop(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> sk1, sk2;
    TreeNode* p;
    sk1.push_back(root);
    while(!sk1.empty()) {
        p = sk1.top(); sk1.pop();
        sk2.push_back(p);
        if(p->left)
            s1.push(p->left);
        if(p->right)
            s1.push(p->right);
    }

    while(!sk2.empty()) {
        cout << sk2.top()->val << endl;
        sk2.pop();
    }
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
/** leetcode-112 
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
 * 这条路径上所有节点值相加等于目标和。
 */
bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL) return false;
    sum = sum-root->val;
    if(root->left == NULL && root->right == NULL) return sum == 0;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

// the help function for pathSum
void dfs(TreeNode* root, int sum, vector<int>& tmp, vector<vector<int>>& ans) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL && sum == root->val)
        tmp.push_back(root->val);
        ans.push_back(tmp);
        tmp.pop_back();
        return;
    }
    tmp.push_back(root->val);
    dfs(root->left, sum-root->val, tmp, ans);
    dfs(root->right, sum-root->val, tmp, ans);
    tmp.pop_back();
}

/** leetcode-113 路径总和II
 *  
 * 
 */
vector<vector<int>> pathSum(TreeNode* root, int sum) {

}
/** leetcode-98 验证二叉搜索树
 *  @param: the root of a tree
 *  @return: is the root is a valid BST
 */
bool isValidBST(TreeNode* root) {
    if(root == NULL) return true;
    stack<TreeNode*> sk;
    inorder = LONG_MIN;
    while(!sk.empty() || root != NULL) {
        while(root != NULL) {
            sk.push(root);
            root->left;
        }
        root = sk.top();
        sk.pop();
        if(root.val <= inorder) return false;
        inorder = root.val;
        root = root-> right;
    }
    return true;
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

/** leetcode-199 二叉树的右视图
 *  @input: [1, 2, 3, null, 5, null, 4]
 *  @output: [1, 3, 4]
 */
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        ans.push_back(q.front()->val);
        while(size--) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->right) q.push(tmp->right);
            if(tmp->left) q.push(tmp->left);
        }
    }
    return ans;
}

/** leetcode-106 从中序与后序遍历序列构造二叉树
 *  @input: inorder[9, 3, 15, 20, 7] postorder=[9, 15, 7, 20, 3]
 *  @output: TreeNode* root
 */
TreeNode* buildTreeIandP(vector<int>& inorder, vector<int>& postorder) {

}

/** leetcode-102 二叉树的层序遍历
 *  @param: the root node of the tree
 *  @return: the levelOrder result
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> tmp;
    while(!q.empty()) {
        int cnt = q.size();
        while(cnt > 0) {
            TreeNode* node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            cnt--;
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}

/** leetcode-450 删除二叉搜索树中的节点
 *  @param: the root and the key of the node to delete
 *  @return: the root has changed
 */
TreeNode* deleteNode(TreeNode* root, int key) {

}

/** leetcode-
 * 
 * 
 */
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <=i; j++)
            dp[i] += dp[j-1]*dp[i-j];
    }
    return dp[n];
}

/** leetcode-538 把二叉搜索树转换为累加树
 *  @param: the root node of tree
 *  @return: the root node of Greater tree
 */
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    TreeNode* node = root;
    stack<TreeNode*> sk;
    while(!sk.empty() || node != NULL) {
        while(node != NULL) {
            sk.push(node);
            node = node->right;
        }
        node = sk.top(); sk.pop();
        sum += node->val;
        node->val = sum;

        node = node->left;
    }
    return root;
}

/** leetcode-114 二叉树展开为链表
 *  @param: the root node of tree
 *  @return: the head node of linked list
 */
void flatten(TreeNode* root) {
    while(root != NULL) {
        if(root->left == NULL) {
            root = root->right;
        } else {
            TreeNode* node = root->left;
            while(node->right != NULL) 
                node = node->right;
            node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
}

/** leetcode-100 相同的树
 *  @param: the root node of tow tree
 *  @return: if the tree is the same tree
 */
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    return p->val == q->val 
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

int main() {

    return 0;
}