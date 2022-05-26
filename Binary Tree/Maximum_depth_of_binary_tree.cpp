#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int v1 = maxDepth(root->left);
        int v2 = maxDepth(root->right);
        return 1 + max(v1,v2);
    }