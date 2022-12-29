#include <bits/stdc++.h>
using namespace std;

string N;
string ans = "0";
int K, k;
queue <string> q;
set <string> mark;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;	
	if (N.size() == 1 || (N.size() == 2 && N[1] == '0')) {
		cout << -1;
		return 0;
	}
	q.push(N);
	for (int i = 1; i <= K; i++) {
		mark.clear();
		int sz = q.size();
		for (int j = 0; j < sz; j++) BFS();
		if (i == K) {
			while (q.size()) {
				ans = max(ans, q.front());
				q.pop();
			}
		}
	}
	cout << ans;
	return 0;
}

void BFS() {
	string now = q.front();
	q.pop();
	if (mark.count(now)) return;
	mark.insert(now);	
	for (int i = 0; i < N.size(); i++) {
		for (int j = i + 1; j < N.size(); j++) {
			if (i == 0 && N[j] == '0') continue;
			string temp = now;
			swap(temp[i], temp[j]);
			q.push(temp);
		}
	}
}