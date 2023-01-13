#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <int, vector<int>, greater<>> T, D;
	int N, sp = 1;
	double now_t = 0, now_d = 0, now_s = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char t; int a;
		cin >> t >> a;
		if (t == 'T') T.push(a);
		else D.push(a);
	}
	D.push(1000);
	while (D.size() && T.size()) {
		int t = T.top();
		int d = D.top();
		if (now_s * (t - now_t) <= d - now_d) {
			now_d += now_s * (t - now_t);
			now_t = t;
			T.pop();
		}
		else {
			now_t += (d - now_d) / now_s;
			now_d = d;
			D.pop();
		}
		sp++;
		now_s = (1.0 / sp);
	}
	while (T.size()) {
		int t = T.top();
		T.pop();
		now_d += now_s * (t - now_t);
		now_t = t;
		sp++;
		now_s = (1.0 / sp);
	}
	while (D.size()) {
		int d = D.top();
		D.pop();
		now_t += (d - now_d) / now_s;
		now_d = d;
		sp++;
		now_s = (1.0 / sp);
	}
	cout << (int)round(now_t) << '\n';
	return 0;
}