#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr[101];
vector <int> graph[26];
int in_degree[26];
set <int> s;
queue <int> q;

void Topology();

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].length(); j++) s.insert((int)(arr[i][j] - 'a'));
	}
	for (int i = 0; i < N; i++) {
		for (int k = i + 1; k < N; k++) {
			string now = arr[i], next = arr[k];
			int len = min(now.length(), next.length());
			for (int j = 0; j < len; j++) {
				if (now[j] != next[j]) {
					int out = now[j] - 'a', in = next[j] - 'a';
					graph[out].push_back(in);
					in_degree[in]++;
					break;
				}
				else if (j == len - 1) {
					if (now.length() > next.length()) {
						cout << "!";
						return;
					}
				}
			}
		}
	}
	Topology();
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

void Topology() {
	vector <int> ans;
	for (auto i = s.begin(); i != s.end(); i++) if (in_degree[*i] == 0) q.push(*i);
	for (int i = 0; i < s.size(); i++) {
		if (q.size() == 0) {
			cout << "!";
			return;
		}
		else if (q.size() > 1) {
			cout << "?";
			return;
		}
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			if (--in_degree[graph[now][i]] == 0) q.push(graph[now][i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << (char)(ans[i] + 'a');
	}
	return;
}