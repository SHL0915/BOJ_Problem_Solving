#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, B, ans = INF;
int arr[101][101];
pair <int, int> cow[101];
vector <int> x_pos;
vector <int> y_pos;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> cow[i].first >> cow[i].second;
		x_pos.push_back(cow[i].first);
		y_pos.push_back(cow[i].second);
	}
	sort(x_pos.begin(), x_pos.end());
	x_pos.erase(unique(x_pos.begin(), x_pos.end()), x_pos.end());
	sort(y_pos.begin(), y_pos.end());
	y_pos.erase(unique(y_pos.begin(), y_pos.end()), y_pos.end());
	for (int i = 0; i < N; i++) {
		int x_idx = lower_bound(x_pos.begin(), x_pos.end(), cow[i].first) - x_pos.begin();
		int y_idx = lower_bound(y_pos.begin(), y_pos.end(), cow[i].second) - y_pos.begin();
		arr[y_idx][x_idx]++;
	}
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			int one = 0, two = 0, three = 0, four = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i < a && j < b) one += arr[i][j];
					else if (i >= a && j < b) two += arr[i][j];
					else if (i < a && j >= b) three += arr[i][j];
					else if (i >= a && j >= b) four += arr[i][j];
				}
			}
			ans = min(ans, max({ one, two, three, four }));
		}
	}
	cout << ans;
	return 0;
}