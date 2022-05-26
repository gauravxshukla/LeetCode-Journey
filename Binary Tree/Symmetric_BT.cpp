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
    bool helper(TreeNode *l,TreeNode *r){
        //both sub tree null
        if(l==NULL && r==NULL) 
        return true;

        //one of thr sub tree is not null
        if(l==NULL || r==NULL)
            return false;
        
        //val of the sub tree not match
        if(l->val != r->val)
            return false;

        //we Compare l left child with r right child and vice versa 
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        
        //its compare the l & r sub tree recursively
        return helper(root->left,root->right);
    }
};