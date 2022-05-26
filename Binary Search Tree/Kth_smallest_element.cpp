#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

/*
Solution 01: Using Inorder Traversal with array.
            Here we’ll do inorder traversal, which is (left subtree → root → right subtree).
            We will store the values from the left side in our vector, which will be in increasing order.
            Finally, we’ll return (k-1) element from our vector, as it’s in increasing order so it will be kth smallest element.
            Time complexity: O(n), as we’re traversing the whole tree once.

*/
class UsingTraversal {
public:
    vector<int> a;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int ans = a[k-1];
        return ans;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
};

/*
Solution 02: Using Inorder Traversal without array.
            if we do inorder traversal then in kth iteration we’ll get our ans.
            return the ans.
            Time complexity: O(k).
*/

class UsingRecursion {
public:
    int ans;
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(root->right, k);
    }  
};