#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, ans;
int l, r, d, u;
pair<int, int> arr[50000];

int calMin(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int m_x = INF, M_x = 0, m_y = INF, M_y = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		m_x = min(m_x, arr[i].first);
		M_x = max(M_x, arr[i].first);
		m_y = min(m_y, arr[i].second);
		M_y = max(M_y, arr[i].second);
		if (arr[i].first == m_x) l = i;
		if (arr[i].first == M_x) r = i;
		if (arr[i].second == m_y) d = i;
		if (arr[i].second == M_y) u = i;
	}
	ans = min({ calMin(l), calMin(r) ,calMin(d) ,calMin(u) });
	cout << ans;
	return 0;
}

int calMin(int k) {
	int m_x = INF, M_x = 0, m_y = INF, M_y = 0;
	for (int i = 0; i < N; i++) {
		if (i == k) continue;
		m_x = min(m_x, arr[i].first);
		M_x = max(M_x, arr[i].first);
		m_y = min(m_y, arr[i].second);
		M_y = max(M_y, arr[i].second);
	}
	return (M_x - m_x) * (M_y - m_y);
}