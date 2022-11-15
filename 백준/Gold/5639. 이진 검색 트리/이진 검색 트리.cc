#include <iostream>
using namespace std;

int tree[10001], i;

void postorder(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> tree[i]) i++;
	postorder(0, i);
	return 0;
}

void postorder(int left, int right) {
	if (left < right) {
		int start;
		for (start = left + 1; start < right; start++) {
			if (tree[start] > tree[left]) break;
		}
		postorder(left + 1, start);
		postorder(start, right);
		cout << tree[left] << '\n';
	}
	else return;
}