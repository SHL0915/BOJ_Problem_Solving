#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
vector <int> graph[51];
int table[51];

int DP(int node);

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a == -1) continue;
		graph[a].push_back(i);
	}

	memset(table, -1, sizeof(table));
	cout << DP(0);

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

int DP(int node) {
	int& ret = table[node];
	if (ret != -1) return ret;

	ret = INF;
	vector <int> temp;
	for (int i = 0; i < graph[node].size(); i++) temp.push_back(DP(graph[node][i]));
	sort(temp.begin(), temp.end(), greater<>());
	for (int i = 0; i < temp.size(); i++) temp[i] += i + 1;
	
	sort(temp.begin(), temp.end());
	if (temp.size() == 0) ret = 0;
	else ret = temp.back();

	return ret;
}