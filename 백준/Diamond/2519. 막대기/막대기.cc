#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, cnt, id_cnt;
vector <int> graph[6005];
vector <pair<pii, pii>> stick;
int parent[6005], id[6005], ans[6005];
stack <int> st;
vector <vector<int>> SCC;

ll ccw(pii a, pii b, pii c);
pii sub(pii a, pii b);
int cross(pii a, pii b, pii c, pii d);
int DFS(int node);
int convert(int a);

void solve() {
	cin >> N;
	for (int i = 1; i <= 3 * N; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		stick.push_back({ {x1,y1},{x2,y2} });
	}

	for (int i = 0; i < N; i++) {
		int a = 3 * i + 1, b = 3 * i + 2, c = 3 * i + 3;		
		graph[convert(-a)].push_back(convert(b));
		graph[convert(-a)].push_back(convert(c));
		graph[convert(-b)].push_back(convert(a));
		graph[convert(-b)].push_back(convert(c));
		graph[convert(-c)].push_back(convert(a));
		graph[convert(-c)].push_back(convert(b));
	}

	for (int i = 1; i <= 3 * N; i++) {
		for (int j = i + 1; j <= 3 * N; j++) {
			if (cross(stick[i - 1].first, stick[i - 1].second, stick[j - 1].first, stick[j - 1].second)) {
				graph[convert(i)].push_back(convert(-j));
				graph[convert(j)].push_back(convert(-i));
			}
		}
	}

	for (int i = 1; i <= 6 * N; i++) if (parent[i] == 0) DFS(i);

	for (int i = 1; i <= 3 * N; i++) {
		if (id[convert(i)] == id[convert(-i)]) {
			cout << -1;
			return;
		}
	}

	reverse(SCC.begin(), SCC.end());
	memset(ans, -1, sizeof(ans));

	for (vector <int> i : SCC) {
		for (int j : i) {
			int now = (j + 1) / 2;
			if (ans[now] != -1) continue;
			ans[now] = (j % 2) ^ 1;
		}
	}

	vector <int> remove;
	for (int i = 1; i <= 3 * N; i++) {
		if (ans[i] % 2 == 0) remove.push_back(i);
	}

	cout << remove.size() << '\n';
	for (int i : remove) cout << i << " ";

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

ll ccw(pii a, pii b, pii c) {
	pii u = sub(b, a);
	pii v = sub(c, b);
	ll ret = u.first * v.second - u.second * v.first;
	if (ret) ret /= abs(ret);
	return ret;
}

pii sub(pii a, pii b) {
	return { a.first - b.first, a.second - b.second };
}

int cross(pii a, pii b, pii c, pii d) {
	ll ccw1 = ccw(a, b, c) * ccw(a, b, d);
	ll ccw2 = ccw(c, d, a) * ccw(c, d, b);

	if (ccw1 == 0 && ccw2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && b >= c) return 1;
		else return 0;
	}
	else if (ccw1 <= 0 && ccw2 <= 0) return 1;
	else return 0;
}

int DFS(int node) {
	parent[node] = ++cnt;
	int ret = cnt;
	st.push(node);

	for (int next : graph[node]) {
		if (parent[next] == 0) ret = min(ret, DFS(next));
		else if (id[next] == 0) ret = min(ret, parent[next]);
	}

	if (ret == parent[node]) {
		id_cnt++;
		vector <int> scc;
		while (1) {
			int t = st.top(); st.pop();
			id[t] = id_cnt;
			scc.push_back(t);
			if (t == node) break;
		}
		SCC.push_back(scc);
	}

	return ret;
}

int convert(int a) {
	if (a > 0) return a * 2 - 1;
	else return -a * 2;
}