#include <bits/stdc++.h>
using namespace std;

int N, M;
set <string> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		a.insert(s);
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (a.count(s)) b.insert(s);
	}
	cout << b.size() << '\n';
	for (auto i = b.begin(); i != b.end(); i++) cout << (*i) << '\n';
	return 0;
}