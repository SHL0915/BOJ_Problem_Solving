#include <bits/stdc++.h>
using namespace std;

int N, cnt;
vector <int> bm, bw;
priority_queue <int, vector<int>, greater<>> sw, sm;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > 0) bm.push_back(a);
		else sm.push(-a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > 0) bw.push_back(a);		
		else sw.push(-a);			
	}
	sort(bm.begin(), bm.end());
	sort(bw.begin(), bw.end());
	for (int i = 0; i < bm.size(); i++) {
		int now = bm[i];
		while (sw.size()) {
			if (sw.top() <= now) sw.pop();
			else break;
		}
		if (sw.size() == 0) continue;
		else {
			sw.pop();
			cnt++;
		}
	}
	for (int i = 0; i < bw.size(); i++) {
		int now = bw[i];
		while (sm.size()) {
			if (sm.top() <= now) sm.pop();
			else break;
		}
		if (sm.size() == 0) continue;
		else {
			sm.pop();
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}