#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char node;
	struct TreeNode* left, * right;
}TreeNode;

typedef struct {
	TreeNode* root;
}Tree;

Tree* createTree() {
	Tree* T = (Tree*)malloc(sizeof(Tree));	
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->node = 'A';
	T->root->left = NULL;
	T->root->right = NULL;
	return T;
}

void InsertTree(TreeNode* root, char parent, char left, char right) {
	TreeNode* leftchild, *rightchild;
	if (root == NULL)
		return;
	if (root->node != parent) {
		InsertTree(root->right, parent, left, right);
		InsertTree(root->left, parent, left, right);
	}
	else {
		if (left != '.') {
			leftchild = (TreeNode*)malloc(sizeof(TreeNode));
			leftchild->node = left;
			leftchild->left = NULL;
			leftchild->right = NULL;
			root->left = leftchild;
		}
		if (right != '.') {
			rightchild = (TreeNode*)malloc(sizeof(TreeNode));
			rightchild->node = right;
			rightchild->left = NULL;
			rightchild->right = NULL;
			root->right = rightchild;
		}
	}
}

void PreorderTraverse(TreeNode* root) {
	if (root == NULL)
		return;
	else {
		printf("%c", root->node);
		PreorderTraverse(root->left);
		PreorderTraverse(root->right);
	}
}

void InorderTraverse(TreeNode* root) {
	if (root == NULL)
		return;
	else {
		InorderTraverse(root->left);
		printf("%c", root->node);
		InorderTraverse(root->right);
	}
}

void PostorderTraverse(TreeNode* root) {
	if (root == NULL)
		return;
	else {
		PostorderTraverse(root->left);
		PostorderTraverse(root->right);
		printf("%c", root->node);
	}
}

int main(void) {
	int N, i;
	char parent, left, right, c;
	Tree* T = createTree();

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		while ((c = getchar()) == '\n');
		parent = c;
		while ((c = getchar()) == ' ');
		left = c;
		while ((c = getchar()) == ' ');
		right = c;
		InsertTree(T->root, parent, left, right);
	}

	PreorderTraverse(T->root);
	printf("\n");
	InorderTraverse(T->root);
	printf("\n");
	PostorderTraverse(T->root);
	printf("\n");
	return 0;
}