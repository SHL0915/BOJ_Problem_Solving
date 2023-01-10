#include <bits/stdc++.h>
using namespace std;

int N;
stack <pair<int, int>> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, flag = 0;
		cin >> a;
		while (s.size()) {
			if (s.top().first > a) {
				cout << s.top().second << " ";
				flag = 1;
				break;
			}
			else s.pop();
		}
		s.push({ a,i });
		if (flag) continue;
		else cout << "0 ";
	}
	return 0;
}