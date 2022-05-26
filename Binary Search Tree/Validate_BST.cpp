#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};


//Logic - If it is a BST, it will be sorted in inorder traversal.

class UsingTraversal {
    vector<int> tree;
public:
    void inOrder(TreeNode* root) {
        if (root==NULL){
            return;
        }
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        
        inOrder(root);
        for (int i=1; i<tree.size(); i++){
            if (tree[i] <= tree[i-1]){
                return false;
            }
        }
        return true;
    }
};

//Logic - Check if the root is greater than left node in one call, check if the root is less than the right node.

class UsingRecursion {
public:
    bool validate(TreeNode *root, int *max,int *min){
        if(root == NULL){
            return true;
        }
        
        if(max!=NULL && root->val>= *max || min!=NULL && root->val <= *min){
            return false;
        }
        
        return validate(root->left,&(root->val),min) && validate(root->right,max,&(root->val));
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root,NULL,NULL);
    }
};