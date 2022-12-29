#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

pair<int, int> dot[4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m_x = INF, m_y = INF, M_x = -1, M_y = -1;
	for (int i = 0; i < 4; i++) {
		cin >> dot[i].first >> dot[i].second;
		m_x = min(m_x, dot[i].first);
		m_y = min(m_y, dot[i].second);
		M_x = max(M_x, dot[i].first);
		M_y = max(M_y, dot[i].second);
	}
	int delt = max(M_x - m_x, M_y - m_y);
	cout << delt * delt;
	return 0;
}