#include <iostream>
using namespace std;

typedef struct Node {
	struct Node* left, * right;
	int val;
}Node;

Node* Insert(Node* root, int data);
void PostOrder(Node* node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int input;
	Node* root = NULL;
	while (cin >> input) root = Insert(root, input);
	PostOrder(root);
	return 0;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->val = data;
		return root;
	}
	if (data > root->val) root->right = Insert(root->right, data);
	else root->left = Insert(root->left, data);
	return root;
}

void PostOrder(Node* node) {
	if (node == NULL) return;
	PostOrder(node->left);
	PostOrder(node->right);
	cout << node->val << '\n';
	return;
}