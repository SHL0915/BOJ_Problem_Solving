#include <iostream>
#include <vector>
using namespace std;

int N, M, flag, cnt, case_num = 1;
vector <int> tree[501];
int mark[501];

void clear();
void DFS(int vertex, int parent);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		clear();
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			tree[A].push_back(B);
			tree[B].push_back(A);
		}
		for (int i = 1; i <= N; i++) {
			if (mark[i] == 0) {
				flag = 0;
				cnt++;
				DFS(i, 0);
				if (flag == 1) cnt--;
			}
		}
		cout << "Case " << case_num++ << ": ";
		switch (cnt) {
		case 0: cout << "No trees.\n"; break;
		case 1: cout << "There is one tree.\n"; break;
		default: cout << "A forest of " << cnt << " trees.\n";
		}
	}
	return 0;
}

void clear() {
	cnt = 0;
	for (int i = 1; i <= N; i++) {
		mark[i] = 0;
		tree[i].clear();
	}
}

void DFS(int vertex, int parent) {
	if (mark[vertex] != 0) {
		flag = 1;
		return;
	}
	mark[vertex] = 1;
	for (int i = 0; i < tree[vertex].size(); i++) {
		if (tree[vertex][i] != parent) DFS(tree[vertex][i], vertex);
	}
	return;
}