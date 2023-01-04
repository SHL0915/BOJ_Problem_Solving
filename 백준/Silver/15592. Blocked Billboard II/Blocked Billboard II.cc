#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int arr[2005][2005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x1, x2, y1, y2;
	for (int i = 1; i >= 0; i--) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1000, x2 += 1000, y1 += 1000, y2 += 1000;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) arr[y][x] = i;
		}
	}
	int m_x = INF, m_y = INF, M_x = -1, M_y = -1;
	for (int i = 0; i < 2005; i++) {
		for (int j = 0; j < 2005; j++) {
			if (arr[i][j]) {
				m_x = min(m_x, j);
				m_y = min(m_y, i);
				M_x = max(M_x, j);
				M_y = max(M_y, i);
			}
		}
	}
	if (m_x == INF) cout << 0;
	else cout << (M_x - m_x + 1) * (M_y - m_y + 1);
	return 0;
}