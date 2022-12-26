#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;

struct cmp {
	bool operator() (piii A, piii B) {
		if (A.first.first == B.first.first) return A.second < B.second;
		return A.first.first > B.first.first;
	}
};

struct smaller {
	bool operator() (int A, int B) {
		return A > B;
	}
};

long long N, K, cnt = 1, now, ans, pos, id;
pair<int, int> arr[100001];
priority_queue <piii, vector<piii>, cmp> c;
priority_queue <int, vector<int>, smaller> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < K; i++) s.push(i);
	for (int i = 0; i < N; i++) {
		if (s.size() == 0) {
			piii t = c.top();
			c.pop();
			now = t.first.first;
			id = t.first.second;
			pos = t.second;
			s.push(pos);
			ans += (cnt * id);
			cnt++;
			while (c.size()) {
				if (c.top().first.first != now) break;
				id = c.top().first.second;
				s.push(c.top().second);
				c.pop();
				ans += (cnt * id);
				cnt++;
			}
		}
		c.push({ {arr[i].second + now,arr[i].first}, s.top() });
		s.pop();
	}
	while (c.size()) {
		id = c.top().first.second;
		ans += (long long)(cnt * id);
		cnt++;
		c.pop();	
	}
	cout << ans;
	return 0;
}