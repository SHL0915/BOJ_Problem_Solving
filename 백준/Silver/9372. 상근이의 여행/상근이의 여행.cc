#include <iostream>
using namespace std;

int T, N, M, ans, u, v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) cin >> u >> v;		
		cout << N - 1 << '\n';
	}
	return 0;
}