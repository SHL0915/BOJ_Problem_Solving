#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 1, cnt = 1;
pair <int, int> island[100000];
int mark[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		island[i] = { height,i };
	}	
	sort(island, island + N);
	for (int i = 0; i < N; i++) {
		int pos = island[i].second;
		mark[pos] = 1;
		int ll = (pos > 0 && mark[pos - 1] == 0);
		int rl = (pos < N - 1 && mark[pos + 1] == 0);
		if (ll && rl) cnt++;
		else if (!ll && !rl) cnt--;
		if (i == N - 1 || island[i].first < island[i + 1].first) ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}