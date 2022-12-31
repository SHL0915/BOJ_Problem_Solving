#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[100];
int mark[4];
int turn[4];

void BF(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	BF(1);
	cout << ans;
	return 0;
}

void BF(int k) {
	if (k == 4) {
		int cnt = 0;	
		map <pair<int, int>, int> m;
		m[{turn[1], turn[2]}] = 1;
		m[{turn[2], turn[3]}] = 1;
		m[{turn[3], turn[1]}] = 1;
		for (int i = 0; i < N; i++) cnt += m[{arr[i].first, arr[i].second}];		
		ans = max(ans, cnt);
		return;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				turn[k] = i;
				BF(k + 1);
				mark[i] = 0;
			}
		}
	}
}