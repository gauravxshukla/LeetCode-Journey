#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        
        // base case 2
        if(root==p || root==q){
            return root;
        }
        
        // now sending the recursion in left and right
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        // if we get the value from both left and right of a node then that node is the LCA and simply return it
        if(left!=NULL && right!=NULL){
            return root;
        }
        // if we only get value from left side , then return left node 
        if(left!=NULL){
            return left;
        }
        // else if we only get value from right side, then return right node
        else{
            return right;
        }
    }
};