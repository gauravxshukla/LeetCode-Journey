#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

class Balanced_BT {
public:
    bool ans;
    int checkBalance(TreeNode* root){
        if(root==NULL)
            return 0;
        if(ans==false) // if Answer is already False then return it.
            return 0;
        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        
        //For this problem,a binary tree is defined as the one in which the left and right subtrees
        //of every node differ in height by no more than 1.
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        ans = true;
        int temp = checkBalance(root);
        return ans;
    }
};