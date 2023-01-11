#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, m = INF, ans;
int org[1001], parent[1001];
pair<int, int> arr[1001];
vector <int> cycle[1001];

int Find(int a);
void Union(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> org[i];
		arr[i] = { org[i],i };
		m = min(m, org[i]);
		parent[i] = i;
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) Union(i, arr[i].second);
	for (int i = 1; i <= N; i++) cycle[Find(i)].push_back(org[i]);
	for (int i = 1; i <= N; i++) {
		if (cycle[i].size() >= 2) {
			int base = INF, sz = cycle[i].size(), sum = 0;
			for (int j = 0; j < cycle[i].size(); j++) {
				sum += cycle[i][j];
				base = min(base, cycle[i][j]);
			}
			ans += sum;
			if (base + m * (sz + 1) < base * (sz - 2)) ans += base + m * (sz + 1);
			else ans += base * (sz - 2);
		}
	}
	cout << ans;
	return 0;
}

int Find(int a) {
	if (a == parent[a]) return parent[a];
	else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) parent[a] = b;
	else parent[b] = a;
	return;
}