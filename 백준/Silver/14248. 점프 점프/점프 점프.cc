#include <iostream>
using namespace std;

int N, S, ans;
int stone[100000];
int mark[100000];

void DFS(int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> stone[i];
	cin >> S;
	DFS(S - 1);
	for (int i = 0; i < N; i++) if (mark[i] == 1) ans++;
	cout << ans;
	return 0;
}

void DFS(int pos) {
	if (pos < 0 || pos >= N) return;
	if (mark[pos] != 0) return;
	mark[pos] = 1;
	DFS(pos + stone[pos]);
	DFS(pos - stone[pos]);
	return;
}