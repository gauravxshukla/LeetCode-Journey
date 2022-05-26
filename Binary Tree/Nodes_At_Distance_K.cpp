#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
};

void printAtLevelK(TreeNode* root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}

int printNodesAtDistanceK(TreeNode* root, TreeNode* target,int k){

	//base case
	if(root==NULL){
		return -1;
	}

	//reach the target node
	if(root==target){
		printAtLevelK(target,k);
		return 0;
	}


	//other case
	int DL = printNodesAtDistanceK(root->left,target,k);
	if(DL!=-1){

		//2 cases
		// Print the current node
		if(DL + 1 ==k){
			cout << root->data;
		}
		// or print somenodes in the rightsubtree
		else{
			printAtLevelK(root->right,k-2-DL);
		}
		return 1 + DL;
	}
	int DR = printNodesAtDistanceK(root->right,target,k);
	if(DR!=-1){
		//2 cases
		//print current node
		if(DR + 1 ==k){
			cout<< root->data <<" ";
		}
		else{
			printAtLevelK(root->left,k-2-DR);
		}
		return 1 + DR;
	}
	return -1;
}