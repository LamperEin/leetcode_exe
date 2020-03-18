#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
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

int main() {

    return 0;
}