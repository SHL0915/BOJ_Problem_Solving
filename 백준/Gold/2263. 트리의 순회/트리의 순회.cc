#include <iostream>
using namespace std;

int N;
int inorder[100001];
int postorder[100001];

void preorder(int iLeft, int iRight, int pLeft, int pRight);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> inorder[i];
	for (int i = 0; i < N; i++) cin >> postorder[i];
	preorder(0, N - 1, 0, N - 1);
	return 0;
}

void preorder(int iLeft, int iRight, int pLeft, int pRight) {
	if (iLeft > iRight) return;
	if (iLeft == iRight) cout << inorder[iLeft] << " ";
	else if (iLeft == iRight - 1) cout << postorder[pRight] << " " << postorder[pLeft] << " ";
	else {
		int root = postorder[pRight];
		int mid;
		for (mid = 0; mid <= iRight - iLeft; mid++) if (inorder[iLeft + mid] == root) break;
		cout << root << " ";
		preorder(iLeft, iLeft + mid - 1, pLeft, pLeft + mid - 1);
		preorder(iLeft + mid + 1, iRight, pLeft + mid, pRight - 1);
	}
}