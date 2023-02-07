#include <iostream>
#include <vector>
using namespace std;

int N;
int tree[26][2];

void preorder(int vertex);
void inorder(int vertex);
void postorder(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char A, B, C;
		cin >> A >> B >> C;
		if (B != '.') tree[A - 'A'][0] = B - 'A';
		else tree[A - 'A'][0] = -1;
		if (C != '.') tree[A - 'A'][1] = C - 'A';
		else tree[A - 'A'][1] = -1;
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
}

void preorder(int vertex) {
	if (vertex == -1) return;
	cout << (char)(vertex + 'A');
	preorder(tree[vertex][0]);
	preorder(tree[vertex][1]);
}

void inorder(int vertex) {
	if (vertex == -1) return;
	inorder(tree[vertex][0]);
	cout << (char)(vertex + 'A');
	inorder(tree[vertex][1]);
}

void postorder(int vertex) {
	if (vertex == -1) return;
	postorder(tree[vertex][0]);
	postorder(tree[vertex][1]);
	cout << (char)(vertex + 'A');
}