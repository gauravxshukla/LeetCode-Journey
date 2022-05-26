#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


//With Hashmap
class Using_HashMap{
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        unordered_map<int, int> inorderMap;
        for (int i=0; i<inorder.size(); i++) inorderMap[inorder[i]] = i;
        return constructTree(preorder, inorderMap, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* constructTree(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& rootIdx, int left, int right) {
        if (left>right) return nullptr;
        
        int pivot = inorderMap[preorder[rootIdx]];
        
        TreeNode* node = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        node->left = constructTree(preorder, inorderMap, rootIdx, left, pivot-1);
        node->right = constructTree(preorder, inorderMap, rootIdx, pivot+1, right);
        return node;
    }
};

class Without_HashMap{
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return constructTree(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left>right) return nullptr;       
		
        int pivot = left;
        while(preorder[rootIdx] != inorder[pivot]) pivot++;
        
        TreeNode* node = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        node->left = constructTree(preorder, inorder, rootIdx, left, pivot-1);
        node->right = constructTree(preorder, inorder, rootIdx, pivot+1, right);
        return node;
    }
};