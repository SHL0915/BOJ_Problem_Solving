#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> piii;
const int INF = 0x3f3f3f3f;

int N, M, ans = INF;
int arr[8][8];
int temp[8][8];
vector <piii> CCTV;
int BT[8];

void BackTracking(int k);
void Color(int x, int y, int dir);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 6) arr[i][j] = 2;
			else if (arr[i][j] != 0) {
				CCTV.push_back({ {j,i},arr[i][j] });
				arr[i][j] = 0;
			}
		}
	}
	BackTracking(0);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == CCTV.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) temp[i][j] = arr[i][j];
		}
		for (int i = 0; i < CCTV.size(); i++) {
			int x = CCTV[i].first.first;
			int y = CCTV[i].first.second;
			int type = CCTV[i].second;
			int dir = BT[i];
			Color(x, y, dir);
			switch (type) {
			case 2: {
				Color(x, y, (dir + 2) % 4);
				break;
			}
			case 3: {
				Color(x, y, (dir + 1) % 4);
				break;
			}
			case 4: {
				Color(x, y, (dir + 1) % 4);
				Color(x, y, (dir + 2) % 4);
				break;
			}
			case 5: {
				Color(x, y, (dir + 1) % 4);
				Color(x, y, (dir + 2) % 4);
				Color(x, y, (dir + 3) % 4);
				break;
			}
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) if (temp[i][j] == 0) cnt++;
		}
		ans = min(ans, cnt);
	}
	else {
		for (int i = 0; i < 4; i++) {
			BT[k] = i;
			BackTracking(k + 1);
		}
	}
}

void Color(int x, int y, int dir) {
	if (x < 0 || x > M - 1 || y < 0 || y > N - 1) return;
	if (temp[y][x] == 2) return;
	temp[y][x] = 1;
	switch (dir) {
	case 0: {
		Color(x + 1, y, dir);
		break;
	}
	case 1: {
		Color(x, y + 1, dir);
		break;
	}
	case 2: {
		Color(x - 1, y, dir);
		break;
	}
	case 3: {
		Color(x, y - 1, dir);
		break;
	}	
	}
}