#include <iostream>
#include <vector>
using namespace std;

int T, N, root, u, v;
int mark[10001];
vector <int> tree[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			tree[i].clear();
			mark[i] = 0;
		}
		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;
			tree[B].push_back(A);
		}
		cin >> u >> v;
		int now = u;
		while (1) {
			mark[now] = 1;
			if (tree[now].size() == 0) break;
			now = tree[now][0];			
		}
		now = v;
		while (1) {
			if (mark[now] == 1) {
				cout << now << '\n';
				break;
			}
			if (tree[now].size() == 0) break;
			now = tree[now][0];
		}		
	}
	return 0;
}