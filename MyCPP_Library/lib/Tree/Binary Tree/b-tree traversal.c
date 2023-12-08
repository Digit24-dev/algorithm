#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode{
	char data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* left, treeNode* right){
	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// 전위 순회
void preorder(treeNode* root){
	if(root){
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 중위 순회
void inorder(treeNode* root){
	if(root){
		printf("%c", root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

// 후위 순회
void postorder(treeNode* root){
	if(root){
		printf("%c", root->data);
		postorder(root->left);
		postorder(root->right);
	}
}