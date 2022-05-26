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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if(!root)
            return ans;
        
        queue <TreeNode*> q;
        q.push(root);
        int count = 1; // we want reverse the list at alternate order
        
        while(!q.empty()){
            int n = q.size();
            vector<int> cur_lvl;
            
            while(n--){
                TreeNode* cur_node=q.front();
                q.pop();
                cur_lvl.push_back(cur_node->val);
                if(cur_node->left)
                    q.push(cur_node->left);
                if(cur_node->right)
                    q.push(cur_node->right);
            }

            if(count%2==0) // we want reverse the list at alternate order
                reverse(cur_lvl.begin(),cur_lvl.end());
            ans.push_back(cur_lvl);
            count++;
        }
        return ans;
    }
};