#include <iostream>
#include <algorithm>
using namespace std;

int H, W, N, ans;
pair<int, int> sticker[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		int R, C;
		cin >> R >> C;
		sticker[i] = { R,C };
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int flag = 0;
			if (sticker[i].first <= H && sticker[j].first <= H - sticker[i].first) {
				if (sticker[i].second <= W && sticker[j].second <= W) flag = 1;
			}
			else if (sticker[i].first <= H && sticker[j].first <= H) {
				if (sticker[i].second <= W && sticker[j].second <= W - sticker[i].second) flag = 1;
			}
			if (sticker[i].second <= H && sticker[j].first <= H - sticker[i].second) {
				if (sticker[i].first <= W && sticker[j].second <= W) flag = 1;
			}
			else if (sticker[i].second <= H && sticker[j].first <= H) {
				if (sticker[i].first <= W && sticker[j].second <= W - sticker[i].first) flag = 1;
			}
			if (sticker[i].first <= H && sticker[j].second <= H - sticker[i].first) {
				if (sticker[i].second <= W && sticker[j].first <= W) flag = 1;
			}
			else if (sticker[i].first <= H && sticker[j].second <= H) {
				if (sticker[i].second <= W && sticker[j].first <= W - sticker[i].second) flag = 1;
			}
			if (sticker[i].second <= H && sticker[j].second <= H - sticker[i].second) {
				if (sticker[i].first <= W && sticker[j].first <= W) flag = 1;
			}
			else if (sticker[i].second <= H && sticker[j].second <= H) {
				if (sticker[i].first <= W && sticker[j].first <= W - sticker[i].first) flag = 1;
			}
			if (flag == 1) ans = max(ans, sticker[i].first * sticker[i].second + sticker[j].first * sticker[j].second);
		}
	}
	cout << ans;
	return 0;
}