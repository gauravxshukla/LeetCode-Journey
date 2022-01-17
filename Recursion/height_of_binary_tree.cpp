#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    struct tree{
        int val;
        tree* left;
        tree* right;
    };

    int height(tree* root){
        //Base Condition
        if(root==NULL){
            return 0;
        }

        //Hypothesis - Thinking of one step lower
        int lh=height(root->left);
        int rh=height(root->right);

        //Induction - Yaha calculation ho rahi hai bidu
        return 1+ max(lh,rh); 
    }
};