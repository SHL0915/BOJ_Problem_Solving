#include <iostream>
#include <queue>
using namespace std;

int primeNum[10000];
int T, A, B, ans, flag;
queue <pair <int, int>> q;
int mark[10000];

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	primeNum[0] = 1;
	primeNum[1] = 1;
	for (int i = 2; i < 10000; i++) {
		if (primeNum[i] == 0) for (int j = i * i; j < 10000; j += i) primeNum[j] = 1;		
	}
	cin >> T;
	while (T--) {
		ans = -1;
		flag = 0;
		for (int i = 0; i < 10000; i++) mark[i] = 0;
		cin >> A >> B;
		q.push({ A, 0 });
		while (q.size()) BFS();
		if (ans == -1) cout << "Impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	int now = temp.first;
	int d = temp.second;
	if (flag == 1) return;
	if (now < 1000 || primeNum[now] == 1) return;
	if (mark[now] != 0) return;
	mark[now] = 1;
	if (now == B) {
		ans = d;
		flag = 1;
		return;
	}
	for (int i = 0; i < 10; i++) q.push({ now % 1000 + i * 1000,d + 1 });
	for (int i = 0; i < 10; i++) q.push({ (now / 1000) * 1000 + i * 100 + now % 100,d + 1 });
	for (int i = 0; i < 10; i++) q.push({ (now / 100) * 100 + i * 10 + now % 10,d + 1 });
	for (int i = 0; i < 10; i++) q.push({ (now / 10) * 10 + i,d + 1 });
	return;
}