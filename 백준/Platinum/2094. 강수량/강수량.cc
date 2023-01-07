#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
pair<ll, ll> arr[50002];
vector <ll> compressed;
int parent[50002][20];
int level[50002];
ll table[50002][20];

void pre(int node, int par, int lv);
long long query(ll A, ll B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		compressed.push_back(arr[i].first);
	}	
	arr[N + 1] = { 1e+10, 1e+10 };
	compressed.push_back(1e+10);
	sort(compressed.begin(), compressed.end());
	compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
	for (int i = 1; i <= N; i++) {
		arr[i].first = lower_bound(compressed.begin(), compressed.end(), arr[i].first) - compressed.begin() + 1;
	}
	pre(1, 1, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		ll c_a, c_b;
		int a, b, type;
		cin >> c_a >> c_b;
		a = lower_bound(compressed.begin(), compressed.end(), c_a) - compressed.begin();
		b = lower_bound(compressed.begin(), compressed.end(), c_b) - compressed.begin();
		if (compressed[a] == c_a && compressed[b] == c_b) {
			type = 0;
			a++; b++;
		}
		else if (compressed[a] == c_a && compressed[b] != c_b) {
			type = 1;
			a++; b++;
		}
		else if (compressed[a] != c_a && compressed[b] == c_b) {
			type = 2;
			b++;
		}
		else type = 3;
		if (type == 0) {
			if (arr[a].second < arr[b].second) {
				cout << "false\n";
				continue;
			}
			if (query(a, b) < arr[b].second) {
				if (b - a == compressed[b - 1] - compressed[a - 1]) cout << "true\n";
				else cout << "maybe\n";
			}
			else cout << "false\n";
		}
		else if (type == 1) {
			if (query(a, b) < arr[a].second) cout << "maybe\n";
			else cout << "false\n";
		}
		else if (type == 2) {
			if (query(a, b) < arr[b].second) cout << "maybe\n";
			else cout << "false\n";
		}
		else cout << "maybe\n";
	}
	return 0;
}

void pre(int node, int par, int lv) {
	if (node == N + 2) return;
	level[node] = lv;
	parent[node][0] = par;
	table[node][0] = max(arr[node].second, arr[par].second);
	for (int i = 1; i < 20; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
		table[node][i] = max(table[node][i - 1], table[parent[node][i - 1]][i - 1]);
	}
	pre(node + 1, node, lv + 1);
	return;
}

long long query(ll A, ll B) {
	int now = parent[B][0];
	if (now == A) return -1;
	ll ret = arr[now].second;
	for (int i = 19; i >= 0; i--) {
		if (level[parent[now][i]] > level[A]) {
			ret = max(ret, table[now][i]);
			now = parent[now][i];
		}
	}
	return ret;
}