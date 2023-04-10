#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string arr[1001];
map <string, int> name;
map <int, string> rvs;
vector <int> up[1001], down[1001];
vector <int> root;

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		name[arr[i]] = i + 1;
		rvs[i + 1] = arr[i];
	}
	

	cin >> M;
	for (int i = 0; i < M; i++) {
		string a, b;
		cin >> a >> b;
		int aa = name[a];
		int bb = name[b];
		up[aa].push_back(bb);
		down[bb].push_back(aa);		
	}

	for (int i = 1; i <= N; i++) {
		if (up[i].size() == 0) root.push_back(i);		
	}

	cout << root.size() << '\n';
	for (int i = 0; i < root.size(); i++) cout << rvs[root[i]] << " ";
	cout << '\n';

	for (int i = 1; i <= N; i++) {
		sort(down[i].begin(), down[i].end());
		down[i].erase(unique(down[i].begin(), down[i].end()), down[i].end());

		vector <int> ans;
		for (int j = 0; j < down[i].size(); j++) {
			int now = down[i][j];
			if (up[now].size() == up[i].size() + 1) ans.push_back(now);
		}

		cout << rvs[i] << " " << ans.size() << " ";
		for (int j = 0; j < ans.size(); j++) cout << rvs[ans[j]] << " ";
		cout << '\n';
	}

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