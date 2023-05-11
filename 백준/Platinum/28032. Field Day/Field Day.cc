#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, C;
string arr[100005];
string rvs[100005];
vector <int> graph[(1<<20)];
int mark[(1 << 20)];
queue <pii> q;

int convert(string s);
void BFS();

void solve() {
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'G') rvs[i] += 'H';
			else rvs[i] += 'G';
		}
		q.push({ convert(arr[i]), 0});
	}

	memset(mark, -1, sizeof(mark));
	while (q.size()) BFS();

	for (int i = 0; i < N; i++) cout << C - mark[convert(rvs[i])] << '\n';
	
	return;
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int convert(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 2;
		ret += (s[i] == 'G');
	}
	return ret;
}

void BFS() {
	pii f = q.front(); q.pop();
	int now = f.first;
	int d = f.second;
	if (mark[now] != -1) return;
	mark[now] = d;

	for (int i = 0; i < C; i++) q.push({ now ^ (1 << i), d + 1 });
	
	return;
}