#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

/* 
    Approach - To get the right side view of a tree,
                we choose BFS Traversal as it traverses the whole tree level by level.
              To get the right side view of any level,
                we will store the value of the last element of any level in our result array.
    
*/



vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> result;
        
        //Applying BFS Search
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            //Storing the size of the new level.
            int level_size = q.size();

            //Traversing the whole level.
            for(int i=0;i<level_size;i++){
                TreeNode* current_node = q.front();
                q.pop();
                
                //Last node for a particular level.
                if(i==level_size-1) 
                    result.push_back(current_node->val);
                
                if(current_node->left)
                    q.push(current_node->left);
                if(current_node->right)
                    q.push(current_node->right);
            }
        }
    return result;   
}