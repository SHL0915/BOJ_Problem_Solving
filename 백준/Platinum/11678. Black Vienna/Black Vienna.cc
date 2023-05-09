#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt, id_cnt, ans;
vector <int> org[155];
vector <int> graph[155];
int id[155], par[155];
stack <int> st;

int convert(char card, int player, int type);
int DFS(int node);

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int a, b;
		cin >> a >> b;
		if (b == 0) {
			org[convert(s[0], a, 0)].push_back(convert(s[0], a, 1));
			org[convert(s[1], a, 0)].push_back(convert(s[1], a, 1));
		}
		else if (b == 1) {
			org[convert(s[0], a, 1)].push_back(convert(s[1], a, 0));
			org[convert(s[1], a, 1)].push_back(convert(s[0], a, 0));
			org[convert(s[0], a, 0)].push_back(convert(s[1], a, 1));
			org[convert(s[1], a, 0)].push_back(convert(s[0], a, 1));
		}
		else {
			org[convert(s[0], a, 1)].push_back(convert(s[0], a, 0));
			org[convert(s[1], a, 1)].push_back(convert(s[1], a, 0));
		}
	}

	for (int i = 1; i <= 26; i++) {
		for (int j = i + 1; j <= 26; j++) {
			for (int k = j + 1; k <= 26; k++) {

				for (int l = 0; l < 155; l++) {
					graph[l].clear();
					for (int m : org[l]) graph[l].push_back(m);
				}

				for (int l = 1; l <= 26; l++) {
					char now = 'A' + (l - 1);
					if (l == i || l == j || l == k) {
						graph[convert(now, 1, 0)].push_back(convert(now, 1, 1));
						graph[convert(now, 2, 0)].push_back(convert(now, 2, 1));
					}
					else {
						graph[convert(now, 1, 1)].push_back(convert(now, 2, 0));
						graph[convert(now, 2, 1)].push_back(convert(now, 1, 0));
						graph[convert(now, 1, 0)].push_back(convert(now, 2, 1));
						graph[convert(now, 2, 0)].push_back(convert(now, 1, 1));
					}
				}

				cnt = 0; id_cnt = 0;
				memset(par, 0, sizeof(par));
				memset(id, 0, sizeof(id));
				for (int l = 1; l <= 4 * 26; l++) if (par[l] == 0) DFS(l);

				int flag = 1;

				for (int l = 1; l <= 26; l++) {
					char now = 'A' + (l - 1);
					if (id[convert(now, 1, 0)] == id[convert(now, 1, 1)] || id[convert(now, 2, 0)] == id[convert(now, 2, 1)]) flag = 0;
				}

				ans += flag;
			}
		}
	}

	cout << ans;

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

int convert(char card, int player, int type) {
	int ret = card - 'A' + 1;
	ret *= 2;
	if (player == 1) ret -= 1;
	ret *= 2;
	if (type == 0) ret -= 1;
	return ret;
}

int DFS(int node) {
	par[node] = ++cnt;
	int ret = cnt;
	st.push(node);
	
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (par[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, par[next]);
	}

	if (ret == par[node]) {
		id_cnt++;
		while (1) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			if (t == node) break;
		}
	}

	return ret;
}